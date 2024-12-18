#include <dragon.h>
#include <visitors.h>

Dragon::Dragon(int x, int y, std::string name) : NPC(DragonType, x, y, name) {}
Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

bool Dragon::accept(Visitor &visitor) noexcept { return visitor.visit(*this); }