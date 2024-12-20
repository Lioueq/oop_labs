#include <gameFunctions.h>
#include <map.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>
#include <random>

const int SIZE = 10;
std::mutex moveMtx;
std::mutex printMtx;

// Функция для генерации случайного числа от 1 до 6
int roll_dice() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1, 6);
    return dis(gen);
}

void mapThread(Map& map) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lock(printMtx);
        map.print();
        std::cout << "----------------------------------------------------------------------------" << '\n';
    }
}


#include <queue>
#include <mutex>
#include <condition_variable>

// Структура для хранения задачи боя
struct FightTask {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

// Очередь задач и мьютекс для синхронизации
std::queue<FightTask> fightQueue;
std::mutex fightQueueMtx;
std::condition_variable fightQueueCv;

void moveThread(std::set<std::shared_ptr<NPC>>& npcs, Map& map) {
    while (true) {
        std::lock_guard<std::mutex> lock(moveMtx);
        for (auto& npc : npcs) {
            for (auto& npc2 : npcs) {
                if (npc->is_close(npc2, npc->attack_range) && NPC::enemy(npc, npc2)) {
                    std::lock_guard<std::mutex> fightLock(fightQueueMtx);
                    fightQueue.push({npc, npc2});
                    fightQueueCv.notify_one();
                }
            }
            int move_points_x = std::rand() % (2 * npc->move_range + 1) - npc->move_range;
            int move_points_y = std::rand() % (2 * npc->move_range + 1) - npc->move_range;
            int nx = (npc->x + move_points_x + SIZE) % SIZE;
            int ny = (npc->y + move_points_y + SIZE) % SIZE;
            if (nx < 0) nx += SIZE;
            if (ny < 0) ny += SIZE;
            map.move(npc, nx, ny);
            npc->x = nx;
            npc->y = ny;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void fightThread(std::set<std::shared_ptr<NPC>>& npcs, Map& map) {
    while (true) {
        std::unique_lock<std::mutex> lock(fightQueueMtx);
        fightQueueCv.wait(lock, [] { return !fightQueue.empty(); });

        FightTask task = fightQueue.front();
        fightQueue.pop();
        lock.unlock();

        int attack_strength = roll_dice();
        int defense_strength = roll_dice();
        if (attack_strength > defense_strength) {
            task.defender->fight_notify(task.attacker, true);
            std::lock_guard<std::mutex> npcsLock(moveMtx);
            npcs.erase(task.defender);
            map.remove_NPC(task.defender);
        } else {
            task.defender->fight_notify(task.attacker, false);
        }
    }
}

int main() {
    std::srand(std::time(nullptr));
    std::set<std::shared_ptr<NPC>> array;
    add_NPC(array, factory(KnightErrantType, 0, 0, "Hollow"));
    add_NPC(array, factory(KnightErrantType, 3, 3, "Kingslayer"));
    add_NPC(array, factory(DragonType, 5, 5, "Alduin"));
    add_NPC(array, factory(PegasusType, 2, 2, "Sagan"));
    Map map = {SIZE};
    for (auto i: array) {
        map.add_NPC(i);
    }
    std::thread printer(mapThread, std::ref(map));
    std::thread mover(moveThread, std::ref(array), std::ref(map));
    std::thread fighter(fightThread, std::ref(array), std::ref(map));
    
    // Ожидание завершения потоков
    printer.join();
    mover.join();
    fighter.join();

    return 0;
}