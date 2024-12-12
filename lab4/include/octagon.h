#pragma once
#include "figure.h"
#include <iostream>
#include <memory>
#include <cmath>

template <Scalar T>
class Octagon : public Figure<T> {
public:
    Octagon(std::unique_ptr<Point<T>> p1, std::unique_ptr<Point<T>> p2, std::unique_ptr<Point<T>> p3, std::unique_ptr<Point<T>> p4,
            std::unique_ptr<Point<T>> p5, std::unique_ptr<Point<T>> p6, std::unique_ptr<Point<T>> p7, std::unique_ptr<Point<T>> p8)
        : p1(std::move(p1)), p2(std::move(p2)), p3(std::move(p3)), p4(std::move(p4)),
          p5(std::move(p5)), p6(std::move(p6)), p7(std::move(p7)), p8(std::move(p8)) {}
    ~Octagon() noexcept = default;

    // Конструктор копирования
    Octagon(const Octagon& other)
        : p1(std::make_unique<Point<T>>(*other.p1)),
          p2(std::make_unique<Point<T>>(*other.p2)),
          p3(std::make_unique<Point<T>>(*other.p3)),
          p4(std::make_unique<Point<T>>(*other.p4)),
          p5(std::make_unique<Point<T>>(*other.p5)),
          p6(std::make_unique<Point<T>>(*other.p6)),
          p7(std::make_unique<Point<T>>(*other.p7)),
          p8(std::make_unique<Point<T>>(*other.p8)) {}

    // Оператор сравнения
    bool operator==(const Octagon& other) const {
        return *p1 == *other.p1 && *p2 == *other.p2 && *p3 == *other.p3 && *p4 == *other.p4 &&
               *p5 == *other.p5 && *p6 == *other.p6 && *p7 == *other.p7 && *p8 == *other.p8;
    }

    operator double() const override {
        T area = 0;
        area += p1->get_x() * p2->get_y() - p2->get_x() * p1->get_y();
        area += p2->get_x() * p3->get_y() - p3->get_x() * p2->get_y();
        area += p3->get_x() * p4->get_y() - p4->get_x() * p3->get_y();
        area += p4->get_x() * p5->get_y() - p5->get_x() * p4->get_y();
        area += p5->get_x() * p6->get_y() - p6->get_x() * p5->get_y();
        area += p6->get_x() * p7->get_y() - p7->get_x() * p6->get_y();
        area += p7->get_x() * p8->get_y() - p8->get_x() * p7->get_y();
        area += p8->get_x() * p1->get_y() - p1->get_x() * p8->get_y();
        return std::abs(area) / 2.0;
    }

    Point<double> geometric_center() const override {
        double x_center = (p1->get_x() + p2->get_x() + p3->get_x() + p4->get_x() +
                      p5->get_x() + p6->get_x() + p7->get_x() + p8->get_x()) / 8.0;
        double y_center = (p1->get_y() + p2->get_y() + p3->get_y() + p4->get_y() +
                      p5->get_y() + p6->get_y() + p7->get_y() + p8->get_y()) / 8.0;
        return Point<double>(x_center, y_center);
    }

    void print() override {
        std::cout << "Octagon: "
                  << "p1 " << *p1 << " p2 " << *p2 << " p3 " << *p3 << " p4 " << *p4
                  << " p5 " << *p5 << " p6 " << *p6 << " p7 " << *p7 << " p8 " << *p8 << '\n';
    }

private:
    std::unique_ptr<Point<T>> p1, p2, p3, p4, p5, p6, p7, p8;
};