#include <gameFunctions.h>


int main() {
    std::set<std::shared_ptr<NPC>> array;

    array.insert(factory(KnightErrantType, 0, 0, "Hollow"));
    array.insert(factory(KnightErrantType, 50, 50, "Kingslayer"));
    array.insert(factory(DragonType, 5, 5, "Alduin"));
    array.insert(factory(PegasusType, 2, 2, "Sagan"));
    std::cout << array << '\n';
    save(array, "npc.txt");

    std::set<std::shared_ptr<NPC>> array2;
    array2 = load("npc.txt");
    std::cout << "Fight starts:\n";
    auto dead_list = fight(array2, 10);

    std::cout << "Died:\n";
    for (auto i : dead_list) {
        std::cout << *i << std::endl;
    }
    return 0;
}