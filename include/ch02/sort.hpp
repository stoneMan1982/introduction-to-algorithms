//
// Created by 杨文宇 on 2019-05-24.
//

#pragma once

template <typename T, typename CompareFunc>
void insert_sort(T *elements, int size, CompareFunc compare) {
    for(int i = 1;i < size;i++) {
        T key(elements[i]);
        int j = i - 1;
        while(j >= 0 && compare(elements[j], key)) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
}

template <typename T, typename CompareFunc>
void insert_sort(T &elements, CompareFunc compare) {
    for(int i = 1;i < elements.size();i++) {
        int j = i - 1;
        typename T::value_type key(elements[i]);
        while(j >= 0 && compare(elements[j], key)) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
}