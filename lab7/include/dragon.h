#pragma once
#include <NPC.h>

class Visitor;

class Dragon : public NPC {
   public:
    Dragon(int x, int y, std::string name);
    Dragon(std::istream &is);

    int move_range = 50;
    int attack_range = 30;

    bool accept(Visitor &visitor) noexcept override;
};
