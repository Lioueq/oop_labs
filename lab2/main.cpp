#include <iostream>
#include "three.h"


int main() {
    Three arr1{'0', '2', '1'};
    arr1.print(std::cout) << '\n';

    Three arr2{'2', '0', '1'};
    arr2.print(std::cout) << '\n';

    Three arr3(arr1.add(arr2));
    arr3.print(std::cout) << '\n';

    Three arr4(std::move(arr3));
    arr4.print(std::cout) << '\n';

    Three arr5(Three{'1', '2'});
    arr5.print(std::cout) << '\n';

    try {
        Three arr6 = arr1.subtract(arr2);
        arr6.print(std::cout) << '\n';
    }

    catch(std::exception &ex) {
        std::cerr << "exception: " << ex.what() << '\n';
    }
    return 0;
}