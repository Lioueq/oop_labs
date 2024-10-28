#pragma once
#include <utility>

class Figure {
    public:
        virtual std::pair<double, double> center() = 0;
        virtual ~Figure() = default;
        virtual operator double() = 0;
        virtual void print_center() = 0;
};