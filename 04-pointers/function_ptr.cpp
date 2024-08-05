#include <cstdio>

using Operator = void (*)(int, int);

// Function that takes a function pointer as a parameter
void executeOperation(Operator operation, int a, int b) {
    operation(a, b);
}

// Functions with the same signature
void multiply(int a, int b) {
    printf("Multiplication: %d\n", a * b);
}

void divide(int a, int b) {
    if (b != 0)
        printf("Division: %d\n", a / b);
    else
        printf("Cannot divide by zero\n");
}

int main() {
    // Calling executeOperation with different functions
    executeOperation(&multiply, 6, 2); // Output: Multiplication: 12
    executeOperation(&divide, 6, 2);   // Output: Division: 3

    return 0;
}
