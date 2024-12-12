#pragma once
#include <concepts>
#include <iostream>
#include "point.h"


template <Scalar T>
class Figure {
    public:
        Figure() = default;
        virtual ~Figure() = default;

        virtual void print() = 0;
        virtual operator double() const = 0;

        virtual Point<double> geometric_center() const = 0;

};