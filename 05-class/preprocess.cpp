#include <iostream>

// Declare the function with the always_inline attribute
inline int multiply(int a, int b) __attribute__((always_inline));

// Define the function
inline int multiply(int a, int b) {
    return a * b;
}

int main() {
    int x = 5, y = 10;
    int result = multiply(x, y);
    std::cout << "The result is: " << result << std::endl;
    return 0;
}
