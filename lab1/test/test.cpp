#include <gtest/gtest.h>
#include "../include/lab1.h"

TEST(test_01, basic_test_set) {
    ASSERT_TRUE(converse(0) == "sıfır");
}

TEST(test_02, basic_test_set) {
    ASSERT_TRUE(converse(5) == "beş");
}

TEST(test_03, basic_test_set) {
    ASSERT_TRUE(converse(11) == "on bir");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
    