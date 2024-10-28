#include "triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) 
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

Triangle::~Triangle() noexcept {}

Triangle::Triangle(const Triangle& other) 
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3) {}

Triangle::Triangle(Triangle&& other) noexcept 
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3) {
    other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = 0;
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        x1 = other.x1; y1 = other.y1;
        x2 = other.x2; y2 = other.y2;
        x3 = other.x3; y3 = other.y3;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        x1 = other.x1; y1 = other.y1;
        x2 = other.x2; y2 = other.y2;
        x3 = other.x3; y3 = other.y3;
        other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = 0;
    }
    return *this;
}

bool Triangle::operator==(const Triangle& other) const {
    return x1 == other.x1 && y1 == other.y1 && x2 == other.x2 && y2 == other.y2 &&
           x3 == other.x3 && y3 == other.y3;
}

std::pair<double, double> Triangle::center() {
    double x_c = (x1 + x2 + x3) / 3;
    double y_c = (y1 + y2 + y3) / 3;
    return {x_c, y_c};
}

void Triangle::print_center() {
    auto [x_c, y_c] = center();
    std::cout << "Geometric center of the triangle: (" << x_c << ", " << y_c << ")" << std::endl;
}

Triangle::operator double() {
    double area = std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
    return area;
}

std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
    os << "Triangle vertices: (" << triangle.x1 << ", " << triangle.y1 << "), ("
       << triangle.x2 << ", " << triangle.y2 << "), ("
       << triangle.x3 << ", " << triangle.y3 << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Triangle& triangle) {
    is >> triangle.x1 >> triangle.y1 >> triangle.x2 >> triangle.y2 >> triangle.x3 >> triangle.y3;
    return is;
}