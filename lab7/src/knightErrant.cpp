#include <knightErrant.h>
#include <visitors.h>

KnightErrant::KnightErrant(int x, int y, std::string name)
    : NPC(KnightErrantType, x, y, name) {
        move_range = 30;
        attack_range = 10;
    }

KnightErrant::KnightErrant(std::istream &is) : NPC(KnightErrantType, is) {
        attack_range = 10;
        move_range = 30;
}

bool KnightErrant::accept(Visitor &visitor) noexcept {
    return visitor.visit(*this);
}