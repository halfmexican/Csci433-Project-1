#include "sorting_algorithms.h"

// Implementation of insertion sort
void insertion_sort(double *a, const size_t n) {
    for (size_t i = 1; i < n; ++i) {
        double key = a[i];
        size_t j = i;
        while ((j > 0) && (key < a[j - 1])) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = key;
    }
}

