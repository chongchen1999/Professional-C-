#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

template <typename T>
struct SumOp {
    T operator()(const T &a, const T &b) const {
        return a + b;
    }

    static T add(const T &a, const T &b) {
        return a + b;
    }
};

int main() {
    const int iters = 1e9;

    // Timing the first loop
    auto start1 = std::chrono::high_resolution_clock::now();

    auto intSum = SumOp<int>();
    auto doubleSum = SumOp<double>();
    for (int i = 0; i < iters; ++i) {
        int a = SumOp<int>()(i, i);
        double b = SumOp<double>()(static_cast<double>(i), static_cast<double>(i));
        // int a = intSum(i, i);
        // double b = doubleSum(static_cast<double>(i), static_cast<double>(i));
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;
    std::cout << "Time for first loop: " << elapsed1.count() << " seconds" << std::endl;

    // Timing the second loop
    auto start2 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iters; ++i) {
        // int a = SumOp<int>::add(i, i);
        // double b = SumOp<double>::add(static_cast<double>(i), static_cast<double>(i));
        int a = intSum(i, i);
        double b = doubleSum(static_cast<double>(i), static_cast<double>(i));
    }

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;
    std::cout << "Time for second loop: " << elapsed2.count() << " seconds" << std::endl;

    return 0;
}
