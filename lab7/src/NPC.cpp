#include <NPC.h>

NPC::NPC(NpcType t, int _x, int _y, std::string name)
    : type(t), x(_x), y(_y), name(name) {}

NPC::NPC(NpcType t, std::istream &is) {
    type = t;
    is >> x;
    is >> y;
    is >> name;
}

void NPC::subscribe(std::shared_ptr<IFightObserver> observer) noexcept {
    observers.push_back(observer);
}

void NPC::fight_notify(std::shared_ptr<NPC> defender, bool win) noexcept {
    for (auto &o : observers) o->on_fight(shared_from_this(), defender, win);
}

void NPC::save(std::ostream &os) noexcept {
    os << type << ' ' << x << ' ' << y << ' ' << name << '\n';
}

bool NPC::enemy(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2) noexcept {
    if (npc1->type + npc2->type == 3) { return true; }
    else if (npc1->type + npc2->type == 5) { return true; }
    return false;
}

bool NPC::is_close(const std::shared_ptr<NPC> &other,
                   size_t distance) noexcept {
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <=
        std::pow(distance, 2))
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, NPC &npc) noexcept {
    switch (npc.type) {
        case KnightErrantType:
            os << "type: KnightErrant ";
            break;
        case PegasusType:
            os << "type: Pegasus ";
            break;
        case DragonType:
            os << "type: Dragon ";
            break;

        default:
            break;
    }
    os << "name: " << npc.name << " coords {x:" << npc.x << ", y:" << npc.y
       << "}";
    return os;
}

void NPC::print() noexcept { std::cout << *this; }
