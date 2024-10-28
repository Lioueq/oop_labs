#pragma once

#include "figure.h"
#include <utility>

class Square : public Figure {
    private:
        double x1, y1, x2, y2, x3, y3, x4, y4;  
    public:
        Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
        ~Square() noexcept;
        std::pair<double, double> center() override;
        void print_center() override;

        operator double() override;
};