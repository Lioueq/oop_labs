#pragma once
#include "gameFunctions.h"

class Map {
    public:
        Map(int size);
        void add_NPC(std::shared_ptr<NPC> npc);
        void print();
    private:
        std::vector<std::vector<std::shared_ptr<NPC>>> map;
};