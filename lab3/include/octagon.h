#pragma once

#include "figure.h"
#include <utility>
#include <iostream>

class Octagon : public Figure {
    private:
        double x[8], y[8];
    public:
        Octagon(double x[8], double y[8]);
        ~Octagon() noexcept;
        Octagon(const Octagon& other);
        Octagon(Octagon&& other) noexcept;
        Octagon& operator=(const Octagon& other);
        Octagon& operator=(Octagon&& other) noexcept;
        bool operator==(const Octagon& other) const;

        std::pair<double, double> center() override;
        void print_center() override;
        operator double() override;

        friend std::ostream& operator<<(std::ostream& os, const Octagon& octagon);
        friend std::istream& operator>>(std::istream& is, Octagon& octagon);
};