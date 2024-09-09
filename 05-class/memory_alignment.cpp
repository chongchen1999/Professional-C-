#include <iostream>

struct Example {
    char a;   // 1 字节
    int b;    // 4 字节
    short c;  // 2 字节
};

int main() {
    std::cout << "Example size: " << sizeof(Example) << std::endl;
    return 0;
}