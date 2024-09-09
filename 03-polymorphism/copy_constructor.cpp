#include <iostream>

struct Operator {
    int a;
    Operator() : a{0} {
        std::cout << "Operator()" << std::endl;
    }
    Operator(int a) : a{a} {
    }
    Operator operator+(const Operator &b) const {
        std::cout << "operator+ (const Operator &b) const" << std::endl;
        return {a + b.a};
    }

    Operator &operator=(const Operator &b) {
        std::cout << "operator= (const Operator &b)" << std::endl;
        a = b.a;
        return *this;
    }
};

/*Operator operator+ (const Operator &a, const Operator &b) {
    std::cout << "operator+ (const Operator &a, const Operator &b)" << std::endl;
    return {a.a + b.a};
}*/




int main() {
    Operator a = {1};
    Operator b = {2};
    Operator c = {0};
    c = a.operator+(b);
    a.operator=(b);
    std::cout << a.a << std::endl;
    std::cout << b.a << std::endl;
    std::cout << c.a << std::endl;

    std::cout << Operator().operator+({10}).a << std::endl;

    return 0;
}