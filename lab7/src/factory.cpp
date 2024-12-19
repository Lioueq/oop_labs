#include <../include/factory.h>
std::shared_ptr<NPC> factory(std::istream &is) noexcept {
    std::shared_ptr<NPC> result;
    int type{0};

    is >> type;
    switch (type) {
        case KnightErrantType:
            result = std::make_shared<KnightErrant>(is);
            break;
        case DragonType:
            result = std::make_shared<Dragon>(is);
            break;
        case PegasusType:
            result = std::make_shared<Pegasus>(is);
            break;
        default:
            std::cerr << "unexpected NPC type:" << type << std::endl;
            break;
    }

    if (result) {
        result->subscribe(TextObserver::get());
        result->subscribe(LogObserver::get());
    }

    return result;
}

std::shared_ptr<NPC> factory(NpcType type, int x, int y,
                             std::string name) noexcept {
    std::shared_ptr<NPC> result;
    switch (type) {
        case KnightErrantType:
            result = std::make_shared<KnightErrant>(x, y, name);
            break;
        case DragonType:
            result = std::make_shared<Dragon>(x, y, name);
            break;
        case PegasusType:
            result = std::make_shared<Pegasus>(x, y, name);
            break;
        default:
            break;
    }
    if (result) {
        result->subscribe(TextObserver::get());
        result->subscribe(LogObserver::get());
    }
    return result;
}