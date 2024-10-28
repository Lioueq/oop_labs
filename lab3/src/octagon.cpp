#include "octagon.h"
#include <cmath>
#include <iostream>

Octagon::Octagon(double x[8], double y[8]) {
    for (int i = 0; i < 8; ++i) {
        this->x[i] = x[i];
        this->y[i] = y[i];
    }
}

Octagon::~Octagon() noexcept {}

Octagon::Octagon(const Octagon& other) {
    for (int i = 0; i < 8; ++i) {
        x[i] = other.x[i];
        y[i] = other.y[i];
    }
}

Octagon::Octagon(Octagon&& other) noexcept {
    for (int i = 0; i < 8; ++i) {
        x[i] = other.x[i];
        y[i] = other.y[i];
        other.x[i] = other.y[i] = 0;
    }
}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        for (int i = 0; i < 8; ++i) {
            x[i] = other.x[i];
            y[i] = other.y[i];
        }
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 8; ++i) {
            x[i] = other.x[i];
            y[i] = other.y[i];
            other.x[i] = other.y[i] = 0;
        }
    }
    return *this;
}

bool Octagon::operator==(const Octagon& other) const {
    for (int i = 0; i < 8; ++i) {
        if (x[i] != other.x[i] || y[i] != other.y[i]) {
            return false;
        }
    }
    return true;
}

std::pair<double, double> Octagon::center() {
    double x_c = 0, y_c = 0;
    for (int i = 0; i < 8; ++i) {
        x_c += x[i];
        y_c += y[i];
    }
    x_c /= 8;
    y_c /= 8;
    return {x_c, y_c};
}

void Octagon::print_center() {
    auto [x_c, y_c] = center();
    std::cout << "Geometric center of the octagon: (" << x_c << ", " << y_c << ")" << std::endl;
}

Octagon::operator double() {
    double area = 0;
    for (int i = 0; i < 8; ++i) {
        int j = (i + 1) % 8;
        area += x[i] * y[j] - y[i] * x[j];
    }
    return std::abs(area) / 2.0;
}

std::ostream& operator<<(std::ostream& os, const Octagon& octagon) {
    os << "Octagon vertices: ";
    for (int i = 0; i < 8; ++i) {
        os << "(" << octagon.x[i] << ", " << octagon.y[i] << ")";
        if (i < 7) os << ", ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Octagon& octagon) {
    for (int i = 0; i < 8; ++i) {
        is >> octagon.x[i] >> octagon.y[i];
    }
    return is;
}