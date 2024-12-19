#include <dragon.h>
#include <visitors.h>

Dragon::Dragon(int x, int y, std::string name) : NPC(DragonType, x, y, name) {
    attack_range = 30;
    move_range = 50;
}

Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {
    attack_range = 30;
    move_range = 50;
}

bool Dragon::accept(Visitor &visitor) noexcept { return visitor.visit(*this); }