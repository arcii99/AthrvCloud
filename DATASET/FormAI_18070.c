//FormAI DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int i, j, temp;
    clock_t start, end;
    double total_time;

    // Initialize array with random integers
    int array[ARRAY_SIZE];
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand();
    }

    // Bubble Sort
    printf("Bubble Sort\n");
    start = clock();
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    end = clock();
    total_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Sorted in %f seconds\n\n", total_time);

    // Quick Sort
    printf("Quick Sort\n");
    start = clock();
    quick_sort(array, 0, ARRAY_SIZE - 1);
    end = clock();
    total_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Sorted in %f seconds\n\n", total_time);

    return 0;
}

void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high);
        quick_sort(array, low, pivot_index - 1);
        quick_sort(array, pivot_index + 1, high);
    }
}

int partition(int *array, int low, int high) {
    int pivot_value = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++) {
        if (array[j] < pivot_value) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}