#include <gameFunctions.h>
#include <map.h>

const int SIZE = 10;

int main() {
    std::set<std::shared_ptr<NPC>> array;
    add_NPC(array, factory(KnightErrantType, 0, 0, "Hollow"));
    add_NPC(array, factory(KnightErrantType, 6, 8, "Kingslayer"));
    add_NPC(array, factory(DragonType, 5, 5, "Alduin"));
    add_NPC(array, factory(PegasusType, 2, 2, "Sagan"));
    Map map = {SIZE};
    for (auto i: array) {
        map.add_NPC(i);
    }
    map.print();
    return 0;
}