#include "Array.hpp"


void test_add(Array<int>& arr) {
    std::cout << "arr.add() tests:\n";
    for (int i = 0; i < 3; i++) { arr.add(i); }
    try {
        arr.add(1);
    } catch(std::length_error& e) {
        std::cout << e.what() << '\n';
    }
}

void test_del(Array<int>& arr) {
    try {
        arr.del(-1);
    } catch(std::out_of_range& e) {
        std::cout << e.what() << '\n';
    }

    try {
        arr.del(3);
    } catch(std::out_of_range& e) {
        std::cout << e.what() << '\n';
    }

    for (int i = 0; i < 3; i++) {
        int* x = arr.del(0);
        std::cout << x << ' ';
        delete x;
    }

    try {
        arr.del(1);
    } catch(std::length_error& e) {
        std::cout << e.what() << '\n';
    }
}


int main(void) {
    int array[] = {5, 2, 3};
    Array<int> arr (array, 3);
    int* x = arr.lshift();
    std::cout << *x << " ";
    arr.display();
    Array<int> oarr(3);
    test_add(oarr);
    oarr.display();
    test_del(oarr);
    oarr.display();
}
