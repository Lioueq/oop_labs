#include <knightErrant.h>
#include <visitors.h>

KnightErrant::KnightErrant(int x, int y, std::string name)
    : NPC(KnightErrantType, x, y, name) {}
KnightErrant::KnightErrant(std::istream &is) : NPC(KnightErrantType, is) {}

bool KnightErrant::accept(Visitor &visitor) noexcept {
    return visitor.visit(*this);
}