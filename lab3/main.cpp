#include "square.h"
#include "triangle.h"
#include "octagon.h"
#include <iostream>
#include <vector>
#include <memory>

enum class FigureType {
    Square,
    Triangle,
    Octagon
};

void delete_figure_by_index(std::vector<std::unique_ptr<Figure>>& figures, size_t index) {
    index--;
    if (index < figures.size()) {
        figures.erase(figures.begin() + index);
        std::cout << "Figure at index " << index + 1 << " deleted.\n";
    } else {
        std::cout << "Invalid index.\n";
    }
}

void list_figures(const std::vector<std::unique_ptr<Figure>>& figures) {
    double total_area = 0;
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i + 1 << ":\n";
        figures[i]->print_center();
        double area = static_cast<double>(*figures[i]);
        total_area += area;
        std::cout << "Area: " << area << '\n';
    }
    std::cout << "Total area: " << total_area << '\n';
}

void add_figure(std::vector<std::unique_ptr<Figure>>& figures) {
    std::cout << "Enter figure type (s for square, t for triangle, o for octagon): ";
    char type_char;
    std::cin >> type_char;
    FigureType type;
    switch (type_char) {
        case 's':
            type = FigureType::Square;
            break;
        case 't':
            type = FigureType::Triangle;
            break;
        case 'o':
            type = FigureType::Octagon;
            break;
        default:
            std::cout << "Invalid figure type.\n";
            return;
    }

    switch (type) {
        case FigureType::Square: {
            std::cout << "Enter square vertices (x1 y1 x2 y2 x3 y3 x4 y4): ";
            Square square(0, 0, 0, 0, 0, 0, 0, 0);
            std::cin >> square;
            figures.push_back(std::make_unique<Square>(square));
            break;
        }
        case FigureType::Triangle: {
            std::cout << "Enter triangle vertices (x1 y1 x2 y2 x3 y3): ";
            Triangle triangle(0, 0, 0, 0, 0, 0);
            std::cin >> triangle;
            figures.push_back(std::make_unique<Triangle>(triangle));
            break;
        }
        case FigureType::Octagon: {
            std::cout << "Enter octagon vertices (x1 y1 x2 y2 x3 y3 x4 y4 x5 y5 x6 y6 x7 y7 x8 y8): ";
            double x[8], y[8];
            for (int i = 0; i < 8; ++i) {
                std::cin >> x[i] >> y[i];
            }
            Octagon octagon(x, y);
            figures.push_back(std::make_unique<Octagon>(octagon));
            break;
        }
    }
}

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    char choice;
    while (choice != '4') {
        std::cout << "Choose an action:\n1 - add figure\n2 - list figures\n3 - delete figure\n4 - exit\n";
        std::cin >> choice;
        switch (choice) {
            case '1':
                add_figure(figures);
                break;
            case '2':
                list_figures(figures);
                break;
            case '3': {
                std::cout << "Enter the index of the figure to delete: ";
                size_t index;
                std::cin >> index;
                delete_figure_by_index(figures, index);
                break;
            }
            case '4':
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}