#include <iostream>

constexpr int square(int x) {
    return x * x;
}

constexpr int result = square(5); // Computed at compile time

int main() {
    srand(time(NULL));
    // constexpr int random = std::rand();

    return 0;
}