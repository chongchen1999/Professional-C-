#include <iostream>

class Base1 {
public:
    virtual void func1();
};

class Base2 {
public:
    virtual void func2();
};

class Derived : public Base1, public Base2 {
public:
    void func1() override;
    void func2() override;
};

int main() {
    std::cout << sizeof(Base1) << std::endl;
    std::cout << sizeof(Base2) << std::endl;
    std::cout << sizeof(Derived) << std::endl;
    return 0;
}