#pragma once
#include <NPC.h>

class Visitor;

class Dragon : public NPC {
   public:
    Dragon(int x, int y, std::string name);
    Dragon(std::istream &is);

    bool accept(Visitor &visitor) noexcept override;
};
