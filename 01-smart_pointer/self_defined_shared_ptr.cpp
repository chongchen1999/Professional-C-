#include "includes/shared_ptr.h"
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
    SharedPointer<MyClass> sp1(new MyClass());
    {
        SharedPointer<MyClass> sp2 = sp1;
        sp2->display();
        std::cout << "Use count: " << sp2.use_count() << std::endl;
    }
    std::cout << "Use count after scope: " << sp1.use_count() << std::endl;

    return 0;
}
