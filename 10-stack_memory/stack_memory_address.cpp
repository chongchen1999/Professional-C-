#include <iostream>

class MyClass {
public:
    int a;
    MyClass() {
        std::cout << "MyClass()!" << std::endl;
    }
    /*MyClass(const int &a) : a(a) {
        std::cout << "MyClass(const int & )!" << std::endl;
    }
    MyClass(const MyClass &other) : a(other.a) {
        std::cout << "MyClass(const MyClass & )!" << std::endl;
    }*/
    /*MyClass(MyClass &&other) noexcept : a(std::move(other.a)) {
        std::cout << "MyClass(MyClass && )!" << std::endl;
    }*/

    /*MyClass &operator=(const MyClass &other) {
        std::cout << "MyClass &operator=(const MyClass & )!" << std::endl;
        a = other.a;
        return *this;
    }*/

    /*MyClass(const MyClass &other) {
        this->a = other.a;
        std::cout << "MyClass(const MyClass & )!" << std::endl;
    }*/

};

MyClass getMyClass() {
    MyClass my_class1;
    MyClass my_class2;
    my_class2.a = 5;
    std::cout << "my_class address: " << &my_class1 << ' ' << &my_class1.a << ' ' << sizeof(my_class1) << std::endl;
    std::cout << "my_class address: " << &my_class2 << ' ' << &my_class2.a << ' ' << sizeof(my_class2) << std::endl;
    // std::cout << &my_class2 - &my_class1 << std::endl;
    return my_class2;
}

MyClass getMyClass2() {
    MyClass my_class1;
    std::cout << "my_class address: " << &my_class1 << ' ' << &my_class1.a << ' ' << sizeof(my_class1) << std::endl;
    return my_class1;
}

int main() {
    /*{
        MyClass my_class = getMyClass();
        std::cout << "my_class address: " << &my_class << ' ' << my_class.a << std::endl;
        my_class.a = 10;
        MyClass my_class2 = getMyClass();
        std::cout << "my_class address: " << &my_class2 << ' ' << my_class.a << std::endl;
    }*/

    MyClass my_class = getMyClass2();
    std::cout << "my_class address: " << &my_class << ' ' << &my_class.a << ' ' << sizeof(my_class) << std::endl;

    return 0;
}