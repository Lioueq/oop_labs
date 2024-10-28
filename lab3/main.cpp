#include "square.h"


int main() {
    double x1 = 0, y1 = 0, x2 = 5, y2 = 5, x3 = 5, y3 = 0, x4 = 0, y4 = 5;
    Square square(x1, y1, x2, y2, x3, y3, x4, y4);
    square.print_center();
    return 0;
}