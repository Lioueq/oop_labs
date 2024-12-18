#pragma once
#include <lab6.h>

class KnightErrant;
class Dragon;
class Pegasus;
class NPC;

class Visitor {
   public:
    virtual bool visit(KnightErrant &element) = 0;
    virtual bool visit(Dragon &element) = 0;
    virtual bool visit(Pegasus &element) = 0;

    virtual ~Visitor() = default;
};

class NPCFighter : public Visitor {
   public:
    std::shared_ptr<NPC> attacker;

    NPCFighter(std::shared_ptr<NPC> attacker);

    bool visit(KnightErrant &element) noexcept override;

    bool visit(Dragon &element) noexcept override;

    bool visit(Pegasus &element) noexcept override;
};
