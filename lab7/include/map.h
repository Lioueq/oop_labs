#pragma once
#include "gameFunctions.h"

class Map {
    public:
        Map(int size);

        void add_NPC(std::shared_ptr<NPC> npc);
        void remove_NPC(std::shared_ptr<NPC> npc);
        void move(std::shared_ptr<NPC> npc, int x, int y);

        void print();
        void npc_list();

    private:
        std::vector<std::vector<std::shared_ptr<NPC>>> map;
};