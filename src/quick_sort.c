#include "sorting_algorithms.h"
// Implementation of quick sort
void quick_sort(double *a, size_t p, size_t r) {
    if (p < r) {
        double pivot = a[r];
        size_t i = p;
        
        for (size_t j = p; j <= r - 1; ++j) {
            if (a[j] < pivot) {
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                ++i;
            }
        }
        
        double temp = a[i];
        a[i] = a[r];
        a[r] = temp;

        size_t q = i;
        
        if (q > 0) { 
            quick_sort(a, p, q - 1);
        }
        quick_sort(a, q + 1, r);
    }
}

