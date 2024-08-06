#include <iostream>

class Base {
public:
    void staticFunction() { // 非虚函数
        std::cout << "Base static function." << std::endl;
    }
    
    virtual void dynamicFunction(int x = 10) { // 虚函数
        std::cout << "Base dynamic function with x = " << x << std::endl;
    }
};

class Derived : public Base {
public:
    void staticFunction() { // 非虚函数
        std::cout << "Derived static function." << std::endl;
    }
    
    void dynamicFunction(int x = 20) override { // 虚函数
        std::cout << "Derived dynamic function with x = " << x << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    
    basePtr->staticFunction();    // 静态绑定：调用 Base::staticFunction()
    basePtr->dynamicFunction();   // 动态绑定：调用 Derived::dynamicFunction(int x = 20)
    
    delete basePtr;
    return 0;
}
