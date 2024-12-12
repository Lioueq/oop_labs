#include <iostream>
#include <memory>
#include "point.h"
#include "figure.h"
#include "square.h"
#include "triangle.h"
#include "octagon.h"
#include "array.h"

template <Scalar T>
std::unique_ptr<Point<T>> input_point() {
    T x, y;
    std::cin >> x >> y;
    return std::make_unique<Point<T>>(x, y);
}

template <Scalar T>
std::shared_ptr<Square<T>> input_square() {
    auto p1 = input_point<T>();
    auto p2 = input_point<T>();
    auto p3 = input_point<T>();
    auto p4 = input_point<T>();
    return std::make_shared<Square<T>>(std::move(p1), std::move(p2), std::move(p3), std::move(p4));
}

template <Scalar T>
std::shared_ptr<Triangle<T>> input_triangle() {
    auto p1 = input_point<T>();
    auto p2 = input_point<T>();
    auto p3 = input_point<T>();
    return std::make_shared<Triangle<T>>(std::move(p1), std::move(p2), std::move(p3));
}

template <Scalar T>
std::shared_ptr<Octagon<T>> input_octagon() {
    auto p1 = input_point<T>();
    auto p2 = input_point<T>();
    auto p3 = input_point<T>();
    auto p4 = input_point<T>();
    auto p5 = input_point<T>();
    auto p6 = input_point<T>();
    auto p7 = input_point<T>();
    auto p8 = input_point<T>();
    return std::make_shared<Octagon<T>>(std::move(p1), std::move(p2), std::move(p3), std::move(p4),
                                        std::move(p5), std::move(p6), std::move(p7), std::move(p8));
}

int main() {
    Array<std::shared_ptr<Figure<int>>> array;
    bool f = true;

    double area_total = 0;
    while (f) {
        std::cout << "Выберите действие:\n1 - Добавить Square\n2 - Добавить Triangle\n3 - Добавить Octagon\n4 - Напечатать фигуры\n5 - Удалить фигуру\n6 - Выход\n";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Введите координаты 4 точек квадрата (x y): ";
                array.add(input_square<int>());
                break;
            case 2:
                std::cout << "Введите координаты 3 точек треугольника (x y): ";
                array.add(input_triangle<int>());
                break;
            case 3:
                std::cout << "Введите координаты 8 точек восьмиугольника (x y): ";
                array.add(input_octagon<int>());
                break;
            case 4:
                for (size_t i = 0; i < array.size(); ++i) {
                    area_total = 0;
                    double t = static_cast<double>(*array[i]);
                    area_total += t;
                    std::cout << "Индекс: " << i << "\n";
                    array[i]->print();
                    std::cout << "Геометрический центр: " << array[i]->geometric_center() << '\n';
                    std::cout << "Площадь: " << t << '\n';
                }
                std::cout << "Общая площадь: " << area_total << '\n';
                break;
            case 5:
                std::cout << "Введите индекс фигуры для удаления:\n";
                size_t index;
                std::cin >> index;
                if (index < array.size()) {
                    array.remove(index);
                    std::cout << "Фигура удалена" << '\n';
                } else {
                    std::cout << "Неверный индекс" << '\n';
                }
                break;
            case 6:
                f = false;
                break;
            default:
                std::cout << "Неверный выбор" << '\n';
                break;
        }
    }
    return 0;
}
