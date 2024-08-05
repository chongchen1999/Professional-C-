#include <iostream>

class MyClass {
    virtual void a() {}
};

int main() {
    MyClass obj;
    std::cout << sizeof(obj) << std::endl;
    return 0;
}