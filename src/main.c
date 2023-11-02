#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorting_algorithms.h"

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <sorting_method> <num_arrays> <array_size>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    char *method = argv[1];
    int num_arrays = atoi(argv[2]);
    size_t array_size = (size_t) atoi(argv[3]);

    clock_t start, end;
    double cpu_time_used;
    double total_time = 0;

    for (int i = 0; i < num_arrays; ++i) {
        double *arr = (double *) malloc(array_size * sizeof(double));
        for (size_t j = 0; j < array_size; ++j) {
            arr[j] = (double) rand() / RAND_MAX;
        }

        start = clock();

        if (strcmp(method, "insertion") == 0) {
            insertion_sort(arr, array_size);
        } else if (strcmp(method, "selection") == 0) {
            selection_sort(arr, array_size);
        } else if (strcmp(method, "merge") == 0) {
            merge_sort(arr, array_size);
        } else if (strcmp(method, "quick") == 0) {
            quick_sort(arr, 0, array_size - 1);
        } else {
            printf("Invalid sorting method.\n");
            free(arr);
            return 1;
        }

        end = clock();
        
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        total_time += cpu_time_used * 1000; // Convert to milliseconds

        free(arr);
    }
    
    double avg_time = total_time / num_arrays;
    printf("Average time taken to sort array: %.2f ms\n", avg_time);

    return 0;
}

