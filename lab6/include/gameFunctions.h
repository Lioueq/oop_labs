#pragma once
#include <factory.h>

// Game func
std::set<std::shared_ptr<NPC>> fight(std::set<std::shared_ptr<NPC>> &array,
                                     size_t distance) noexcept;
std::ostream &operator<<(std::ostream &os,
                         std::set<std::shared_ptr<NPC>> &array) noexcept;

void add_NPC(std::set<std::shared_ptr<NPC>> &array,
             std::shared_ptr<NPC> npc) noexcept;
void add_NPC(std::set<std::shared_ptr<NPC>> &array, NpcType type, int x, int y,
             std::string name) noexcept;

// File funcs
void save(const std::set<std::shared_ptr<NPC>> &array,
          const std::string &filename) noexcept;
std::set<std::shared_ptr<NPC>> load(const std::string &filename) noexcept;