#include <iostream>

class MyClass {
public:
    int a;
    MyClass() {
        std::cout << "MyClass()!" << std::endl;
    }

    MyClass(const MyClass &other) {
        this->a = other.a;
        std::cout << "MyClass(const MyClass & )!" << std::endl;
    }

};


MyClass getMyClass2() {
    MyClass my_class1;
    std::cout << "my_class address in function: " << &my_class1 << ' ' << &my_class1.a << ' ' << sizeof(my_class1) << std::endl;
    return my_class1;
}

int main() {
    MyClass my_class = getMyClass2();
    std::cout << "my_class address in main: " << &my_class << ' ' << &my_class.a << ' ' << sizeof(my_class) << std::endl;

    return 0;
}