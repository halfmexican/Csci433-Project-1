#include "sorting_algorithms.h"
#include <stdlib.h> 

// Helper function to merge two sorted sub-arrays
void merge(double *a, size_t p, size_t q, size_t r) {
    size_t n1 = q - p + 1;
    size_t n2 = r - q;

    // Create temporary arrays L and R of type double
    double *L = (double*)malloc(n1 * sizeof(double));
    double *R = (double*)malloc(n2 * sizeof(double));

    for (size_t i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (size_t j = 0; j < n2; j++)
        R[j] = a[q + 1 + j];

    size_t i = 0;
    size_t j = 0;
    size_t k = p;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements if any
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }

    // Free temporary arrays
    free(L);
    free(R);
}

// Recursive merge sort function
void merge_sort_recursive(double *a, size_t p, size_t r) {
    if (p < r) {
        size_t q = (p + r) / 2;
        merge_sort_recursive(a, p, q);
        merge_sort_recursive(a, q + 1, r);
        merge(a, p, q, r);
    }
}

void merge_sort(double *a, const size_t n) {
    merge_sort_recursive(a, 0, n - 1);
}

