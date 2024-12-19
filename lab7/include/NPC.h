#pragma once
#include <lab6.h>

class Visitor;
class NPC;

struct IFightObserver {
    virtual void on_fight(const std::shared_ptr<NPC> attacker,
                          const std::shared_ptr<NPC> defender, bool win) = 0;
};

class NPC : public std::enable_shared_from_this<NPC> {
   public:
    NpcType type;
    std::string name;
    int x{0};
    int y{0};
    int attack_range = 0;
    int move_range = 0;
    std::vector<std::shared_ptr<IFightObserver>> observers;

    NPC(NpcType t, int _x, int _y, std::string name);
    NPC(NpcType t, std::istream &is);

    void subscribe(std::shared_ptr<IFightObserver> observer) noexcept;
    void fight_notify(const std::shared_ptr<NPC> defender, bool win) noexcept;

    virtual void save(std::ostream &os) noexcept;
    virtual bool is_close(const std::shared_ptr<NPC> &other,
                          size_t distance) noexcept;
    virtual bool accept(Visitor &visitor) = 0;

    virtual void print() noexcept;

    friend std::ostream &operator<<(std::ostream &os, NPC &npc) noexcept;
};
