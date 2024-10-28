#pragma once

#include "figure.h"
#include <utility>
#include <iostream>

class Square : public Figure {
    private:
        double x1, y1, x2, y2, x3, y3, x4, y4;  
    public:
        Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
        ~Square() noexcept;
        Square(const Square& other);
        Square(Square&& other) noexcept;
        Square& operator=(const Square& other);
        Square& operator=(Square&& other) noexcept;
        bool operator==(const Square& other) const;

        std::pair<double, double> center() override;
        void print_center() override;
        operator double() override;

        friend std::ostream& operator<<(std::ostream& os, const Square& square);
        friend std::istream& operator>>(std::istream& is, Square& square);
};