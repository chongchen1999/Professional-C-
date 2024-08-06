#include <iostream>
#include <utility> // For std::forward

void process(int& x) {
    std::cout << "Lvalue reference\n";
}

void process(int&& x) {
    std::cout << "Rvalue reference\n";
}

template <typename T>
void forwardToProcess(T&& arg) {
    process(std::forward<T>(arg)); // Perfectly forward arg to process
}

int main() {
    int x = 10;
    forwardToProcess(x);          // Calls process(int& x)
    forwardToProcess(20);         // Calls process(int&& x)
    return 0;
}
