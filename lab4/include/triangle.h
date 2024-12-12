#pragma once
#include "figure.h"
#include <iostream>
#include <memory>
#include <math.h>

template <Scalar T>
class Triangle : public Figure<T> {
public:
    Triangle(std::unique_ptr<Point<T>> p1, std::unique_ptr<Point<T>> p2, std::unique_ptr<Point<T>> p3)
        : p1(std::move(p1)), p2(std::move(p2)), p3(std::move(p3)) {}
    ~Triangle() noexcept = default;

    Triangle(const Triangle& other)
        : p1(std::make_unique<Point<T>>(*other.p1)),
          p2(std::make_unique<Point<T>>(*other.p2)),
          p3(std::make_unique<Point<T>>(*other.p3)) {}

    bool operator==(const Triangle& other) const {
        return *p1 == *other.p1 && *p2 == *other.p2 && *p3 == *other.p3;
    }

    operator double() const override {
        double a = std::sqrt(std::pow(p2->get_x() - p1->get_x(), 2) + std::pow(p2->get_y() - p1->get_y(), 2));
        double b = std::sqrt(std::pow(p3->get_x() - p2->get_x(), 2) + std::pow(p3->get_y() - p2->get_y(), 2));
        double c = std::sqrt(std::pow(p1->get_x() - p3->get_x(), 2) + std::pow(p1->get_y() - p3->get_y(), 2));
        double s = (a + b + c) / 2;
        double area = std::sqrt(s * (s - a) * (s - b) * (s - c));
        return static_cast<double>(area);
    }

    Point<double> geometric_center() const override {
        double x_center = (p1->get_x() + p2->get_x() + p3->get_x()) / 3.0;
        double y_center = (p1->get_y() + p2->get_y() + p3->get_y()) / 3.0;
        return Point<double>(x_center, y_center);
    }

    void print() override {
        std::cout << "Triangle: " << "p1 " << *p1 << " p2 " << *p2 << " p3 " << *p3 << '\n';
    }

private:
    std::unique_ptr<Point<T>> p1, p2, p3;
};