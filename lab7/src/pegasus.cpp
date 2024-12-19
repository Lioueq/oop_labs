#include <pegasus.h>
#include <visitors.h>

Pegasus::Pegasus(int x, int y, std::string name)
    : NPC(PegasusType, x, y, name) {
        int move_range = 30;
        int attack_range = 10;
    }
Pegasus::Pegasus(std::istream &is) : NPC(PegasusType, is) {}

bool Pegasus::accept(Visitor &visitor) noexcept { return visitor.visit(*this); }