#include <gameFunctions.h>
#include <visitors.h>

std::set<std::shared_ptr<NPC>> fight(std::set<std::shared_ptr<NPC>> &array,
                                     size_t distance) noexcept {
    std::set<std::shared_ptr<NPC>> dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) &&
                (attacker->is_close(defender, distance))) {
                NPCFighter fighter(attacker);

                bool success = defender->accept(fighter);
                if (success) dead_list.insert(defender);
            }

    return dead_list;
}

std::ostream &operator<<(std::ostream &os,
                         std::set<std::shared_ptr<NPC>> &array) noexcept {
    for (auto i : array) os << (*i) << '\n';
    return os;
}

void save(const std::set<std::shared_ptr<NPC>> &array,
          const std::string &filename) noexcept {
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array) n->save(fs);
    fs.flush();
    fs.close();
}

std::set<std::shared_ptr<NPC>> load(const std::string &filename) noexcept {
    std::set<std::shared_ptr<NPC>> result;
    std::ifstream is(filename);
    if (is.good() && is.is_open()) {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i) result.insert(factory(is));
        is.close();
    } else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}

void add_NPC(std::set<std::shared_ptr<NPC>> &array,
             std::shared_ptr<NPC> npc) noexcept {
    array.insert(npc);
}

void add_NPC(std::set<std::shared_ptr<NPC>> &array, NpcType type, int x, int y,
             std::string name) noexcept {
    array.insert(factory(type, x, y, name));
}