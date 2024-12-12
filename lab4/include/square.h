#pragma once
#include "figure.h"
#include <iostream>
#include <memory>
#include <math.h>

template <Scalar T>
class Square : public Figure<T> {
public:
    Square(std::unique_ptr<Point<T>> p1, std::unique_ptr<Point<T>> p2, std::unique_ptr<Point<T>> p3, std::unique_ptr<Point<T>> p4)
        : p1(std::move(p1)), p2(std::move(p2)), p3(std::move(p3)), p4(std::move(p4)) {}
    ~Square() noexcept = default;

    Square(const Square& other)
        : p1(std::make_unique<Point<T>>(*other.p1)),
          p2(std::make_unique<Point<T>>(*other.p2)),
          p3(std::make_unique<Point<T>>(*other.p3)),
          p4(std::make_unique<Point<T>>(*other.p4)) {}

    bool operator==(const Square& other) const {
        return *p1 == *other.p1 && *p2 == *other.p2 && *p3 == *other.p3 && *p4 == *other.p4;
    }

    operator double() const override {
        T side = std::sqrt(std::pow(abs(p2->get_x() - p1->get_x()), 2) + std::pow(abs(p2->get_y() - p1->get_y()), 2));
        return static_cast<double>(side * side);
    }

    Point<double> geometric_center() const override {
        double x_center = (p1->get_x() + p2->get_x() + p3->get_x() + p4->get_x()) / 4.0;
        double y_center = (p1->get_y() + p2->get_y() + p3->get_y() + p4->get_y()) / 4.0;
        return Point<double>(x_center, y_center);
    }

    void print() override {
        std::cout << "Square: " << "p1 " << *p1 << " p2 " << *p2 << " p3 " << *p3 << " p4 " << *p4 << '\n';
    }

private:
    std::unique_ptr<Point<T>> p1, p2, p3, p4;
};