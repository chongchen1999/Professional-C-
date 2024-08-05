#include <iostream>

struct VTable {
    void (*print)();
};

void base_print() {
    std::cout << "base print!" << std::endl;
}

void derived_print() {
    std::cout << "derived print!" << std::endl;
}

struct Base {
    VTable *vptr;
    Base() {
        vptr = new VTable;
        vptr->print = &base_print;
    }

    ~Base() {
        delete vptr;
    }
};

struct Derived : Base {
    Derived() {
        Base();
        vptr->print = &derived_print;
    }

    ~Derived() {}
};

int main() {
    Base *base = new Base();
    Derived *derived = new Derived();
    Base *derived2 = new Derived();

    base->vptr->print();
    derived->vptr->print();
    derived2->vptr->print();

    delete base;
    delete derived;
    delete derived2;
    return 0;
}