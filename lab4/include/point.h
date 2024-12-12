#pragma once
#include <concepts>
#include <iostream>

template <typename T>
concept Scalar = std::is_default_constructible<T>::value && std::is_scalar<T>::value;


template <Scalar T>
class Point {

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Point& point) {
        T x, y;
        is >> x >> y;
        point.set_x(x);
        point.set_y(y);
        return is;
    }

    public:
        Point(T x_, T y_) : x(x_), y(y_) {}

        void set_x(T x_) { x = x_; };
        void set_y(T y_) { y = y_; };

        T get_x() { return x; }
        T get_y() { return y; }

        void print() {
            std::cout << x << ' ' << y;
        }

    private:
        T x, y;
};