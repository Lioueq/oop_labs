#include <gameFunctions.h>
#include <map.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>

const int SIZE = 10;
std::mutex mtx;

void printMapPeriodically(Map& map) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lock(mtx);
        map.print();
    }
}

int main() {
    std::set<std::shared_ptr<NPC>> array;
    add_NPC(array, factory(KnightErrantType, 0, 0, "Hollow"));
    add_NPC(array, factory(KnightErrantType, 6, 8, "Kingslayer"));
    add_NPC(array, factory(DragonType, 5, 5, "Alduin"));
    add_NPC(array, factory(PegasusType, 2, 2, "Sagan"));
    Map map = {SIZE};
    for (auto i: array) {
        std::cout << i->attack_range;
    }
    std::thread printer(printMapPeriodically, std::ref(map));
    printer.detach();
    
    // Бесконечный цикл, чтобы программа не завершалась сразу
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}