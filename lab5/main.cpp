#include "include/list.h"
#include "include/memory_resource.h"
#include <iostream>

struct Mita {
    std::string name;
    int id;
};

int main() {
    FixedBlockMemoryResource memoryResource(sizeof(Node<int>), 100);
    std::pmr::polymorphic_allocator<Node<int>> alloc(&memoryResource);

    List<int> intList(alloc);
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);

    for (auto it = intList.begin(); it != intList.end(); ++it) {
        std::cout << it->data << '\n';
    }

    FixedBlockMemoryResource complexMemoryResource(sizeof(Node<Mita>), 100);
    std::pmr::polymorphic_allocator<Node<Mita>> complexAlloc(&complexMemoryResource);

    List<Mita> complexList(complexAlloc);
    complexList.push_back({"Mita", 1});
    complexList.push_back({"Mika", 2});

    for (auto it = complexList.begin(); it != complexList.end(); ++it) {
        std::cout << it->data.name << " " << it->data.id << " " << '\n';
    }
    return 0;
}