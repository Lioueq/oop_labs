#include "square.h"
#include <iostream>
#include <cmath>

Square::Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
            this->x3 = x3;
            this->y3 = y3;
            this->x4 = x4;
            this->y4 = y4;
};

std::pair <double, double> Square::center() {
    double x_c = (x1 + x2 + x3 + x4) / 4;
    double y_c = (y1 + y2 + y3 + y4) / 4;
    return std::pair <double, double> {x_c, y_c};
}

void Square::print_center() {
    std::pair <double, double> center = this->center();
    double x_c = center.first, y_c = center.second;
    std::cout << "Геометрический центр квадрата: (" << x_c << ", " << y_c << ")" << std::endl;
}

Square::operator double() {
    // Пример: возвращаем площадь квадрата или другое значение
    return (std::sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))) * 
           (std::sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)));
}

Square::~Square() noexcept {
    ;
}