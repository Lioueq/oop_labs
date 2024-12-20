#pragma once
#include "gameFunctions.h"

class Map {
    public:
        Map(int size);
        void add_NPC(std::shared_ptr<NPC> npc);
        void print();
        void move(std::shared_ptr<NPC> npc, int x, int y);
        void remove_NPC(std::shared_ptr<NPC> npc);
    private:
        std::vector<std::vector<std::shared_ptr<NPC>>> map;
};