#include <pegasus.h>
#include <visitors.h>

Pegasus::Pegasus(int x, int y, std::string name)
    : NPC(PegasusType, x, y, name) {
        attack_range = 10;
        move_range = 30;
    }
Pegasus::Pegasus(std::istream &is) : NPC(PegasusType, is) {
    attack_range = 10;
    move_range = 30;
}

bool Pegasus::accept(Visitor &visitor) noexcept { return visitor.visit(*this); }