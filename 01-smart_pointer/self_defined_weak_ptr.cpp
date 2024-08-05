#include <iostream>
#include "includes/weak_ptr.h"

int main() {
    SharedPtr<int> sp(new int(42));
    WeakPtr<int> wp(sp);

    std::cout << "SharedPtr count: " << (sp.get() ? "Not null" : "Null") << std::endl;

    if (auto locked = wp.lock().get()) {
        std::cout << "WeakPtr locked: " << *locked << std::endl;
    } else {
        std::cout << "WeakPtr expired." << std::endl;
    }

    sp = nullptr; // Reset the SharedPtr, making the object eligible for deletion.

    if (auto locked = wp.lock().get()) {
        std::cout << "WeakPtr locked: " << *locked << std::endl;
    } else {
        std::cout << "WeakPtr expired." << std::endl;
    }

    return 0;
}
