#include <iostream>

int main() {
    int arr[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    auto p = new int[3][5];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            p[i][j] = arr[i][j];
        }
    }

    /*std::cout<< *p << std::endl;
    std::cout << *arr << std::endl;
    std::cout << **arr << std::endl;*/

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << p[i][j] << " " << &p[i][j] << std::endl;
        }
    }
    return 0;
}