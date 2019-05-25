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

    int array[]{3,2,7,6,5,13,10,9};

    std::cout << "before sort:\n\t";
    print_array(array, sizeof(array) / sizeof(array[0]));
    insert_sort(array, sizeof(array) / sizeof(array[0]),[](const int &a, const int &b){ return a < b; });
    std::cout << "after sort:\n\t";
    print_array(array, sizeof(array) / sizeof(array[0]));

    std::vector<int> arr{3,2,7,6,5,13,10,9};

    typedef std::vector<int>::value_type value_type;
    insert_sort(arr,[](value_type &a, value_type &b) {
        return a < b;
    });

    std::cout << "after sort:\n\t";
    for(auto iter = arr.begin();iter != arr.end();++iter) {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;
    return 0;
}