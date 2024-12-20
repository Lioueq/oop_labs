#include <dragon.h>
#include <knightErrant.h>
#include <pegasus.h>
#include <visitors.h>

NPCFighter::NPCFighter(std::shared_ptr<NPC> attacker) : attacker(attacker) {}

bool NPCFighter::visit(KnightErrant &element) noexcept {
    element.fight_notify(attacker, false);
    return false;
}

bool NPCFighter::visit(Dragon &element) noexcept {
    if (attacker->type == KnightErrantType) {
        element.fight_notify(attacker, true);
        return true;
    }
    element.fight_notify(attacker, false);
    return false;
}

bool NPCFighter::visit(Pegasus &element) noexcept {
    if (attacker->type == DragonType) {
        element.fight_notify(attacker, true);
        return true;
    }
    element.fight_notify(attacker, false);
    return false;
}

