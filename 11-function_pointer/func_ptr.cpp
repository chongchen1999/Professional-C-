#include <iostream>

// 一个普通函数
int add(int a, int b) {
    return a + b;
}

int main() {
    using func_ptr = int (*)(int, int);
    func_ptr funcPtr = &add;
    
    // 使用函数指针调用函数
    std::cout << "Result: " << funcPtr(5, 3) << std::endl;
    
    return 0;
}
