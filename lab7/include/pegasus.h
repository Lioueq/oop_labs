#pragma once
#include <NPC.h>

class Visitor;

class Pegasus : public NPC {
   public:
    Pegasus(int x, int y, std::string name);
    Pegasus(std::istream &is);

    bool accept(Visitor &visitor) noexcept override;
};
