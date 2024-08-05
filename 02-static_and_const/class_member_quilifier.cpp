#include <iostream>

class StaticExample {
public:
    static int sharedValue;
    static void printValue() {
        std::cout << "Shared Value: " << sharedValue << std::endl;
    }
};

// int StaticExample::sharedValue = 100;

int main() {
    // if not initialize static class member value explicitly, compile error
    auto x = StaticExample::sharedValue;
    std::cout << x << std::endl;

    StaticExample::printValue(); // Shared Value: 100
    StaticExample::sharedValue = 200;
    StaticExample::printValue(); // Shared Value: 200
    return 0;
}
