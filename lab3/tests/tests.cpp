#include <gtest/gtest.h>
#include "square.h"
#include "triangle.h"
#include "octagon.h"

TEST(SquareTest, AreaCalculation) {
    Square square(0, 0, 0, 2, 2, 2, 2, 0);
    double expected_area = 4.0;
    double area = (double) square;
    EXPECT_DOUBLE_EQ(area, expected_area);
}


TEST(TriangleTest, AreaCalculation) {
    Triangle triangle(0, 0, 0, 3, 4, 0);
    double expected_area = 6.0;
    double area = (double) triangle;
    EXPECT_DOUBLE_EQ(area, expected_area);
}


TEST(OctagonTest, AreaCalculation) {
    double x[8] = {0, 1, 2, 3, 3, 2, 1, 0};
    double y[8] = {0, 1, 1, 0, -1, -2, -2, -1};
    Octagon octagon(x, y);
    double expected_area = 7.0;
    double area = (double) octagon;
    EXPECT_DOUBLE_EQ(area, expected_area);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}