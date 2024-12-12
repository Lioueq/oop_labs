#include <gtest/gtest.h>
#include "square.h"
#include "triangle.h"
#include "array.h"
#include "octagon.h"

TEST(SquareTest, AreaCalculation) {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 1, x3 = 1, y3 = 1, x4 = 1, y4 = 0;
    auto p1 = std::make_unique<Point<int>>(x1, y1);
    auto p2 = std::make_unique<Point<int>>(x2, y2);
    auto p3 = std::make_unique<Point<int>>(x3, y3);
    auto p4 = std::make_unique<Point<int>>(x4, y4);
    auto sq = std::make_shared<Square<int>>(std::move(p1), std::move(p2), std::move(p3), std::move(p4));
    double area = static_cast<double>(*sq);
    EXPECT_DOUBLE_EQ(area, 1.0);
}

TEST(OctagonTest, AreaCalculation) {
    int x1 = 0, y1 = 0, x2 = 1, y2 = 0, x3 = 2, y3 = 1, x4 = 2, y4 = 2;
    int x5 = 1, y5 = 3, x6 = 0, y6 = 3, x7 = -1, y7 = 2, x8 = -1, y8 = 1;
    auto p1 = std::make_unique<Point<int>>(x1, y1);
    auto p2 = std::make_unique<Point<int>>(x2, y2);
    auto p3 = std::make_unique<Point<int>>(x3, y3);
    auto p4 = std::make_unique<Point<int>>(x4, y4);
    auto p5 = std::make_unique<Point<int>>(x5, y5);
    auto p6 = std::make_unique<Point<int>>(x6, y6);
    auto p7 = std::make_unique<Point<int>>(x7, y7);
    auto p8 = std::make_unique<Point<int>>(x8, y8);
    auto oct = std::make_shared<Octagon<int>>(std::move(p1), std::move(p2), std::move(p3), std::move(p4), std::move(p5), std::move(p6), std::move(p7), std::move(p8));
    double area = static_cast<double>(*oct);
    EXPECT_DOUBLE_EQ(area, 7.0);
}

TEST(TriangleTest, AreaCalculation) {
    int x1 = 0, y1 = 0, x2 = 1, y2 = 0, x3 = 0, y3 = 1;
    auto p1 = std::make_unique<Point<int>>(x1, y1);
    auto p2 = std::make_unique<Point<int>>(x2, y2);
    auto p3 = std::make_unique<Point<int>>(x3, y3);
    auto tri = std::make_shared<Triangle<int>>(std::move(p1), std::move(p2), std::move(p3));
    double area = static_cast<double>(*tri);
    EXPECT_DOUBLE_EQ(area, 0.5);
}

TEST(ArrayTest, FigurePointerArray) {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 1, x3 = 1, y3 = 1, x4 = 1, y4 = 0;
    auto p1 = std::make_unique<Point<int>>(x1, y1);
    auto p2 = std::make_unique<Point<int>>(x2, y2);
    auto p3 = std::make_unique<Point<int>>(x3, y3);
    auto p4 = std::make_unique<Point<int>>(x4, y4);
    auto sq = std::make_shared<Square<int>>(std::move(p1), std::move(p2), std::move(p3), std::move(p4));
    Array<std::shared_ptr<Figure<int>>> array;
    array.add(sq);

    EXPECT_DOUBLE_EQ(static_cast<double>(*array[0]), 1.0);
}

TEST(ArrayTest, SquareArray) {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 1, x3 = 1, y3 = 1, x4 = 1, y4 = 0;
    auto p1 = std::make_unique<Point<int>>(x1, y1);
    auto p2 = std::make_unique<Point<int>>(x2, y2);
    auto p3 = std::make_unique<Point<int>>(x3, y3);
    auto p4 = std::make_unique<Point<int>>(x4, y4);
    auto sq = std::make_shared<Square<int>>(std::move(p1), std::move(p2), std::move(p3), std::move(p4));
    Array<std::shared_ptr<Square<int>>> array;
    array.add(sq);

    EXPECT_DOUBLE_EQ(static_cast<double>(*array[0]), 1.0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}