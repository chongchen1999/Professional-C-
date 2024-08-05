#include <memory>
#include <iostream>
int main() {
    // 1. test ownership transfer
    auto ptr1 = std::make_unique<int>(10);
    std::unique_ptr<int> ptr2;
    // ptr2 = ptr1; , not allowed
    ptr2 = std::move(ptr1);
    std::cout << (ptr1 == nullptr) << std::endl; // true
    
    // 2. test raw pointer, do not transfer ownership
    int *raw_ptr = ptr2.get();
    std::cout << (ptr2 == nullptr) << std::endl; // false

    // 3. dangling pointer
    int *raw_ptr2;
    {
        std::unique_ptr<int> ptr3 = std::move(ptr2);
        raw_ptr2 = ptr3.get();
        std::cout << (*raw_ptr2) << std::endl; // 10
    }

    std::cout << (raw_ptr2 == nullptr) << std::endl; // false

    // this is undefined behavior, the memory is already freed
    std::cout << (*raw_ptr2) << std::endl; 

    return 0;
}