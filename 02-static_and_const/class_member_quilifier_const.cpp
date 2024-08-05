#include <iostream>

class MyClass {
public:

    // implicitly add: MyClass *const this
    void printValue() {
        std::cout << "call printValue()" << std::endl;
        std::cout << value << std::endl; // 实际上是 this->value
        std::cout << typeid(this).name() << std::endl; // 打印 this 的类型
    }

    // implicitly add: const MyClass *const this
    void printValue() const {
        std::cout << "call printValue() const" << std::endl; 
        std::cout << value << std::endl; // 实际上是 this->value
        std::cout << typeid(this).name() << std::endl; // 打印 this 的类型
    }

    void foo() {
        std::cout << "call printValue() const" << std::endl; 
        std::cout << value << std::endl; // 实际上是 this->value
        std::cout << typeid(this).name() << std::endl; // 打印 this 的类型
    }



private:
    int value = 41;
    const int constValue = 42;
};

int main() {
    const auto myClass = MyClass();
    auto myClass2 = MyClass();

    myClass.printValue();
    myClass2.printValue();

    // not allowed
    // myClass.foo(); 

    return 0;
}