#include "square.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double calculate_square_area(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    std::vector<std::pair<double, double>> vertices = {
        {x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}
    };
    std::vector<double> distances;
    for (size_t i = 0; i < vertices.size(); ++i) {
        for (size_t j = i + 1; j < vertices.size(); ++j) {
            distances.push_back(distance(vertices[i].first, vertices[i].second, vertices[j].first, vertices[j].second));
        }
    }
    std::sort(distances.begin(), distances.end());
    double side = distances[0];
    return side * side;
}

Square::Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) 
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {}

Square::~Square() noexcept {}

Square::Square(const Square& other) 
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {}

Square::Square(Square&& other) noexcept 
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {
    other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = other.x4 = other.y4 = 0;
}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        x1 = other.x1; y1 = other.y1;
        x2 = other.x2; y2 = other.y2;
        x3 = other.x3; y3 = other.y3;
        x4 = other.x4; y4 = other.y4;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        x1 = other.x1; y1 = other.y1;
        x2 = other.x2; y2 = other.y2;
        x3 = other.x3; y3 = other.y3;
        x4 = other.x4; y4 = other.y4;
        other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = other.x4 = other.y4 = 0;
    }
    return *this;
}

bool Square::operator==(const Square& other) const {
    return x1 == other.x1 && y1 == other.y1 && x2 == other.x2 && y2 == other.y2 &&
           x3 == other.x3 && y3 == other.y3 && x4 == other.x4 && y4 == other.y4;
}

std::pair<double, double> Square::center() {
    double x_c = (x1 + x2 + x3 + x4) / 4;
    double y_c = (y1 + y2 + y3 + y4) / 4;
    return {x_c, y_c};
}

void Square::print_center() {
    auto [x_c, y_c] = center();
    std::cout << "Geometric center of the square: (" << x_c << ", " << y_c << ")" << std::endl;
}

Square::operator double() {
    return calculate_square_area(x1, y1, x2, y2, x3, y3, x4, y4);
}

std::ostream& operator<<(std::ostream& os, const Square& square) {
    os << "Square vertices: (" << square.x1 << ", " << square.y1 << "), ("
       << square.x2 << ", " << square.y2 << "), ("
       << square.x3 << ", " << square.y3 << "), ("
       << square.x4 << ", " << square.y4 << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Square& square) {
    is >> square.x1 >> square.y1 >> square.x2 >> square.y2 >> square.x3 >> square.y3 >> square.x4 >> square.y4;
    return is;
}