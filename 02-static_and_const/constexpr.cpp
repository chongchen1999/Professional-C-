#include <iostream>

const int get_value() {
    return 42;
}

constexpr int get_constexpr_value() {
    return 42;
}

int main() {
    const int x = 10; // 编译时常量
    const int y = get_value(); // 运行时常量
    int z = get_value();

    constexpr int a = 10; // 编译时常量
    // constexpr int b = get_value(); // 错误，get_value()不是constexpr函数
    constexpr int c = get_constexpr_value(); // 正确，get_constexpr_value()是constexpr函数

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "c: " << c << std::endl;

    return 0;
}