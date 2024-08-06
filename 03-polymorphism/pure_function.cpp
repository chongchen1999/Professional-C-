#include <iostream>

// 基类
class Base {
public:
    virtual void pureVirtualFunction() = 0; // 纯虚函数
};

// 纯虚函数的实现
void Base::pureVirtualFunction() {
    std::cout << "Pure virtual function implementation in Base class." << std::endl;
}

// 派生类
class Derived : public Base {
public:
    void pureVirtualFunction() override {
        Base::pureVirtualFunction(); // 调用基类中的纯虚函数实现
        std::cout << "Override in Derived class." << std::endl;
    }
};

int main() {
    Derived obj;
    obj.pureVirtualFunction(); // 调用派生类中的实现
    return 0;
}
