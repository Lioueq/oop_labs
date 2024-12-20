#include <gameFunctions.h>
#include <map.h>

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <stdlib.h>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <thread>

struct FightTask {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

const int SIZE = 10;
const int NPC_COUNT = 50;
const int TIME = 30;

std::set<std::shared_ptr<NPC>> dead;
std::queue<FightTask> fightQueue;

std::mutex npcsMtx;
std::mutex coutMtx;
std::mutex fightQueueMtx;
std::condition_variable fightQueueCv;

std::atomic<bool> running{true};

int rand_num(int range) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, range);
    return dis(gen);
}

void fill_array(std::set<std::shared_ptr<NPC>>& array) {
    for (int i = 0; i < NPC_COUNT; ++i) {
        int type_n = rand_num(3);
        NpcType nt;
        if (type_n == 1) { nt = KnightErrantType; } 
        else if (type_n == 2) { nt = DragonType; } 
        else { nt = PegasusType; }

        add_NPC(array, factory(nt, rand_num(SIZE) - 1, rand_num(SIZE) - 1,
                               std::to_string(i)));
    }
}

void moveThread(std::set<std::shared_ptr<NPC>>& npcs, Map& map) {
    while (running) {
        std::set<std::shared_ptr<NPC>> fighters;
        std::unique_lock<std::mutex> lock(npcsMtx);
        for (auto& npc : npcs) {
            for (auto& npc2 : npcs) {
                if (!dead.contains(npc) && !fighters.contains(npc) &&
                    !fighters.contains(npc2) && npc != npc2 &&
                    npc->is_close(npc2, npc->attack_range) &&
                    NPC::enemy(npc, npc2)) {
                    std::lock_guard<std::mutex> fightLock(fightQueueMtx);
                    fightQueue.push({npc, npc2});
                    fightQueueCv.notify_one();
                    fighters.insert(npc);
                    fighters.insert(npc2);
                    break;
                }
            }
            int move_points_x = rand_num(npc->move_range);
            int move_points_y = rand_num(npc->move_range);
            int nx = (npc->x + move_points_x + SIZE) % SIZE;
            int ny = (npc->y + move_points_y + SIZE) % SIZE;
            if (nx < 0) nx += SIZE;
            if (ny < 0) ny += SIZE;
            map.move(npc, nx, ny);
            npc->x = nx;
            npc->y = ny;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void fightThread(std::set<std::shared_ptr<NPC>>& npcs, Map& map) {
    while (running) {
        std::unique_lock<std::mutex> lock(fightQueueMtx);
        fightQueueCv.wait(lock, [] { return !fightQueue.empty(); });

        FightTask task = fightQueue.front();
        fightQueue.pop();
        lock.unlock();

        int attack_strength = rand_num(6);
        int defense_strength = rand_num(6);
        if (attack_strength > defense_strength) {
            std::unique_lock<std::mutex> lock(npcsMtx);
            npcs.erase(task.defender);
            map.remove_NPC(task.defender);
            dead.insert(task.defender);
            // task.attacker->fight_notify(task.defender, true);
        }
    }
}

int main() {
    std::set<std::shared_ptr<NPC>> array;
    fill_array(array);

    Map map = {SIZE};
    for (auto i : array) {
        map.add_NPC(i);
    }

    std::thread mover(moveThread, std::ref(array), std::ref(map));
    std::thread fighter(fightThread, std::ref(array), std::ref(map));

    auto start_time = std::chrono::steady_clock::now();
    while (std::chrono::steady_clock::now() - start_time <
           std::chrono::seconds(TIME)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::lock_guard<std::mutex> lock(coutMtx);
        map.print();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        system("cls");
    }
    running = false;

    mover.join();
    fighter.join();

    map.npc_list();
    return 0;
}