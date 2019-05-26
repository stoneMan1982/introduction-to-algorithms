#include <iostream>
#include <algorithm>
#include <vector>
#include <ch02/sort.hpp>


void print_array(int *array, int size) {
    for(int i = 0;i < size;i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {

    int array[]{3,2,7,6,5,13,10,9,1,4,8};
    merge_sort(array, 0, sizeof(array) / sizeof(int) - 1,[](int &a, int &b){ return a > b; });
    return 0;
}