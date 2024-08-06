#include <iostream>

#define SIZE 256

void forceUnrollLoop() {
    int arr[SIZE];

    #pragma GCC unroll 4
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = i;
    }
}

int main() {
    forceUnrollLoop();
    return 0;
}
