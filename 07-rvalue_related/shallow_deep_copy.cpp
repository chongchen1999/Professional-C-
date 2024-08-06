#include <iostream>
#include <memory>
#include <algorithm>
#include <cstring>
int main() {
    int *a = new int[5]{1, 2, 3, 4, 5};
    int *b = a; // shallow copy
    int *c = new int[5];
    std::memcpy(c, a, 5 * sizeof(int)); // deep copy

    std::cout << "address of a: " << &a << std::endl;
    std::cout << "address of b: " << &b << std::endl;

    std::for_each(
        a, a + 5,
        [](int &x) {
            std::cout << &x << ' ';
        }
    );
    std::cout << std::endl;

    std::for_each(
        b, b + 5,
        [](int &x) {
            std::cout << &x << ' ';
        }
    );
    std::cout << std::endl;

    int *c = new int(*a); // deep copy

    std::cout << "address of c: " << &c << std::endl;
    std::for_each(
        c, c + 5,
        [](int &x) {
            std::cout << x << ' ';
        }
    );
    std::cout << std::endl;

    return 0;
}