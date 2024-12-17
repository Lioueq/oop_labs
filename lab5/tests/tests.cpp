#include <gtest/gtest.h>
#include "../include/list.h"
#include "../include/memory_resource.h"

TEST(ListTest, PushBackInt) {
    FixedBlockMemoryResource memoryResource(sizeof(Node<int>), 100);
    std::pmr::polymorphic_allocator<Node<int>> alloc(&memoryResource);

    List<int> intList(alloc);
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);

    auto it = intList.begin();
    EXPECT_EQ(it->data, 1);
    ++it;
    EXPECT_EQ(it->data, 2);
    ++it;
    EXPECT_EQ(it->data, 3);
}

TEST(ListTest, PushBackComplexType) {
    struct Mita {
        std::string name;
        int id;
    };

    FixedBlockMemoryResource complexMemoryResource(sizeof(Node<Mita>), 100);
    std::pmr::polymorphic_allocator<Node<Mita>> complexAlloc(&complexMemoryResource);

    List<Mita> complexList(complexAlloc);
    complexList.push_back({"Mita", 1});
    complexList.push_back({"Mika", 2});

    auto it = complexList.begin();
    EXPECT_EQ(it->data.name, "Mita");
    EXPECT_EQ(it->data.id, 1);
    ++it;
    EXPECT_EQ(it->data.name, "Mika");
    EXPECT_EQ(it->data.id, 2);
}

TEST(ListTest, Clear) {
    FixedBlockMemoryResource memoryResource(sizeof(Node<int>), 100);
    std::pmr::polymorphic_allocator<Node<int>> alloc(&memoryResource);

    List<int> intList(alloc);
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    intList.clear();

    EXPECT_EQ(intList.begin(), intList.end());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}