#include "includes/unique_ptr.h"
#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass Destructor" << std::endl;
    }
    void display() const {
        std::cout << "Display MyClass" << std::endl;
    }
};

int main() {
    UniquePtr<MyClass> p1(new MyClass());
    std::cout << "Before scope: " << p1.get() << std::endl;
    {
        UniquePtr<MyClass> p2 = std::move(p1);
    }
    std::cout << "After scope: " << p1.get() << std::endl;

    return 0;
}
