#pragma once

#include "figure.h"
#include <utility>
#include <iostream>

class Triangle : public Figure {
    private:
        double x1, y1, x2, y2, x3, y3;
    public:
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
        ~Triangle() noexcept;
        Triangle(const Triangle& other);
        Triangle(Triangle&& other) noexcept;
        Triangle& operator=(const Triangle& other);
        Triangle& operator=(Triangle&& other) noexcept;
        bool operator==(const Triangle& other) const;

        std::pair<double, double> center() override;
        void print_center() override;
        operator double() override;

        friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle);
        friend std::istream& operator>>(std::istream& is, Triangle& triangle);
};