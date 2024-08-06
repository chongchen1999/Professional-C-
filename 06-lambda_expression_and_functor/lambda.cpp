#include <algorithm>
#include <vector>
#include <iostream>
#include <memory>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::for_each(
        vec.begin(), vec.end(), 
        [](int& n) -> void {
            n *= 2;
        }
    );
    std::for_each(
        vec.begin(), vec.end(), 
        [](const int& n) {
            std::cout << n << " ";
        }
    );
    puts("");

    int val = 0;
    auto arr = std::make_unique<int[]>(10);
    std::for_each(
        arr.get(), arr.get() + 10, 
        [val](int& n) mutable -> void {
            const int &x = ++val;
            n = (233 * x * x + 97 * x + 13) % 47;
        }
    );
    std::for_each(
        arr.get(), arr.get() + 10, 
        [](const int& n) {
            std::cout << n << " ";
        }
    );
    puts("");

    std::sort(
        arr.get(), arr.get() + 10,
        [](const int& a, const int& b) -> bool {
            return a < b;
        }
    );

    std::for_each(
        arr.get(), arr.get() + 10, 
        [](const int& n) {
            std::cout << n << " ";
        }
    );
    puts("");

    return 0;
}