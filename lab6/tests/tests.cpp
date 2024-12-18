#include <gameFunctions.h>
#include <visitors.h>
#include <gtest/gtest.h>


TEST(test_01, basic_test_set) {
    std::set<std::shared_ptr<NPC>> array;

    array.insert(factory(KnightErrantType, 0, 0, "Hollow"));
    array.insert(factory(KnightErrantType, 50, 50, "Kingslayer"));
    array.insert(factory(DragonType, 5, 5, "Alduin"));
    array.insert(factory(PegasusType, 2, 2, "Sagan"));

    auto dead_list = fight(array, 10);
    ASSERT_TRUE(dead_list.size() == 2);
}

TEST(test_02, basic_test_set) {
    std::set<std::shared_ptr<NPC>> array;

    array.insert(factory(KnightErrantType, 0, 0, "Hollow"));
    array.insert(factory(KnightErrantType, 50, 50, "Kingslayer"));
    array.insert(factory(DragonType, 5, 5, "Alduin"));
    array.insert(factory(PegasusType, 2, 2, "Sagan"));

    auto dead_list = fight(array, 25);

    ASSERT_TRUE(dead_list.size() == 2);
}

TEST(test_03, basic_test_set) {
    std::set<std::shared_ptr<NPC>> array;
    auto b = factory(DragonType, 5, 5, "Alduin");
    array.insert(factory(KnightErrantType, 0, 0, "Hollow"));
    array.insert(b);

    auto dead_list = fight(array, 10);

    ASSERT_TRUE(dead_list.contains(b) == true);
}

TEST(test_04, basic_test_set) {
    std::set<std::shared_ptr<NPC>> array;
    auto b = factory(DragonType, 5, 5, "Alduin");
    array.insert(factory(DragonType, 0, 0, "Viperrr"));
    array.insert(b);

    auto dead_list = fight(array, 10);

    ASSERT_TRUE(dead_list.contains(b) == false);
}

TEST(test_05, basic_test_set) {
    std::set<std::shared_ptr<NPC>> array;
    auto b = factory(PegasusType, 5, 5, "Sagan");
    array.insert(factory(DragonType, 100, 100, "Alduin"));
    array.insert(b);

    auto dead_list = fight(array, 10);

    ASSERT_TRUE(dead_list.contains(b) == false);
}

TEST(test_06, basic_test_set) {
    std::set<std::shared_ptr<NPC>> array;
    auto b = factory(PegasusType, 5, 5, "Sagan");
    array.insert(factory(DragonType, 100, 100, "Alduin"));
    array.insert(b);

    auto dead_list = fight(array, 150);

    ASSERT_TRUE(dead_list.contains(b) == true);
}

TEST(test_07, basic_test_set) {
    std::set<std::shared_ptr<NPC>> array;
    auto b = factory(KnightErrantType, 5, 5, "Sagan");
    array.insert(factory(PegasusType, 100, 100, "Alduin"));
    array.insert(b);

    auto dead_list = fight(array, 100);

    ASSERT_TRUE(dead_list.size() == 0);
}

// Trapezoid
TEST(test_08, basic_test_set) {
    auto a = factory(DragonType, 5, 5, "Alduin");
    auto b = factory(KnightErrantType, 5, 5, "Hollow");
    NPCFighter fighter(b);

    ASSERT_TRUE(a->accept(fighter));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}