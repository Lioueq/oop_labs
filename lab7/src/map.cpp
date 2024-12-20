#include "../include/map.h"

Map::Map(int size) : map(size, std::vector<std::shared_ptr<NPC>>(size)) {}

void Map::add_NPC(std::shared_ptr<NPC> npc) {
    int x, y;
    x = npc->x;
    y = npc->y;
    map[x][y] = npc;
}

void Map::move(std::shared_ptr<NPC> npc, int x, int y) {
    std::swap(map[npc->x][npc->y], map[x][y]);
}

void Map::remove_NPC(std::shared_ptr<NPC> npc) {
    map[npc->x][npc->y] = nullptr;
}

void Map::print() {
    for (auto i : map) {
        for (auto j : i) {
            if (j) {
                char className;
                switch (j->type) {
                    case KnightErrantType:
                        className = 'K';
                        break;
                    case PegasusType:
                        className = 'P';
                        break;
                    case DragonType:
                        className = 'D';
                        break;
                    default:
                        className = '.';
                        break;
                }
                std::cout << className;
            } else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }
}
