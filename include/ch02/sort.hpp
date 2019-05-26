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

template <typename T>
inline void copy_array(T *dest, int *src, int size) {
    for(int i = 0;i < size;i++) {
        dest[i] = src[i];
    }
}

template <typename T, typename CompareFunc>
void merge(T *array, int l, int m, int r, CompareFunc compare) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *left = new int[n1]{0};
    int *right = new int[n2]{0};
    copy_array(left, array + l, n1);
    copy_array(right, array + m + 1, n2);

    int i = 0;
    int j = 0;
    for(int k = l;k <= r;k++) {
        if(i >= n1 || j >= n2) {
            for(;i < n1;i++) {
                array[k] = left[i];
                k++;
            }
            for(;j < n2;j++) {
                array[k] = right[j];
                k++;
            }
            break;
        }

        if(compare(left[i], right[j])) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
    }

}

template <typename T, typename CompareFunc>
void merge_sort(T *array, int begin, int end, CompareFunc compare) {
    if(begin < end) {
        int mid = (begin + end) >> 1;
        merge_sort(array, begin, mid, compare);
        merge_sort(array, mid + 1, end, compare);
        merge(array, begin, mid, end, compare);
    }
}