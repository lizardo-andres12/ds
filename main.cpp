#include "Array.hpp"
#include <iostream>


int main(void) {
    Array<int> arr{};
    Array<int> oarr(3);
    oarr.add(2);
    std::cout << oarr[0] << '\n';
    std::cout << oarr[0] << "bool: " << oarr.insert(9, 0) << '\n';
    std::cout << oarr[0] << "bool: " << oarr.insert(3, 0) << '\n';
    std::cout << oarr[0] << "bool: " << oarr.insert(4, 0) << '\n';
    oarr.display();
    int x = oarr.del(2);
    std::cout << x << '\n';
}
