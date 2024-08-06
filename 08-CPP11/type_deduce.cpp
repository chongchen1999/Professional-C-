#include <iostream>
#include <type_traits>

int main() {
    int x = 0;
    int &y = x;
    const int z = 0;

    // 1. decltype(变量)
    decltype(x) a; // a 的类型是 int
    decltype(y) b = y; // b 的类型是 int&，因为 y 是一个左值引用
    decltype(z) c = z; // c 的类型是 const int，因为 z 是一个 const int

    // 2. decltype(表达式)
    decltype(x + 0) d; // d 的类型是 int，因为 x + 0 是一个纯右值
    decltype((x)) e = x; // e 的类型是 int&，因为 (x) 是一个左值
    decltype(std::move(x)) f = std::move(x); // f 的类型是 int&&，因为 std::move(x) 是一个临终值

    // 输出类型信息
    std::cout << std::boolalpha;
    std::cout << "a is int: " << std::is_same<decltype(a), int>::value << "\n";
    std::cout << "b is int&: " << std::is_same<decltype(b), int&>::value << "\n";
    std::cout << "c is const int: " << std::is_same<decltype(c), const int>::value << "\n";
    std::cout << "d is int: " << std::is_same<decltype(d), int>::value << "\n";
    std::cout << "e is int&: " << std::is_same<decltype(e), int&>::value << "\n";
    std::cout << "f is int&&: " << std::is_same<decltype(f), int&&>::value << "\n";

    return 0;
}
