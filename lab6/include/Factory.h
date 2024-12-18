#pragma once
#include <dragon.h>
#include <knightErrant.h>
#include <observer.h>
#include <pegasus.h>

// Фабрики -----------------------------------
std::shared_ptr<NPC> factory(std::istream &is) noexcept;

std::shared_ptr<NPC> factory(NpcType type, int x, int y,
                             std::string name) noexcept;