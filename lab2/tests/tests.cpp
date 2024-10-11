#include <gtest/gtest.h>
#include "../include/three.h"

TEST(test_1, basic_test_set) {
    Three arr1{'1', '1', '1'};
    Three arr2{'2', '0', '1'};
    Three arr3 = arr1.subtract(arr2);
    EXPECT_EQ(arr3.toString(), "2");
}

TEST(test_2, basic_test_set) {
    Three arr1{'1', '1', '1'};
    Three arr2{'1', '1', '1'};
    Three arr3 = arr1.subtract(arr2);
    EXPECT_EQ(arr3.toString(), "0");
}

TEST(test_3, basic_test_set) {
    Three arr1{'2', '0', '1'};
    Three arr2{'1', '1', '1'};
    bool b = arr1.isLessThan(arr2);
    EXPECT_EQ(b, true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
