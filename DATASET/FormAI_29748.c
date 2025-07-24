//FormAI DATASET v1.0 Category: Benchmarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

int main() {
    int i, j;
    clock_t start, end;
    double time_taken;
    int* array = (int*) malloc(sizeof(int) * ARRAY_SIZE);

    // Initialize array
    for(i=0; i<ARRAY_SIZE; i++) {
        array[i] = i;
    }

    // Benchmarking bubble sort
    start = clock();
    for(i=0; i<ARRAY_SIZE-1; i++) {
        for(j=0; j<ARRAY_SIZE-i-1; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    time_taken = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds to execute \n", time_taken);

    // Re-initialize array
    for(i=0; i<ARRAY_SIZE; i++) {
        array[i] = i;
    }

    // Benchmarking selection sort
    start = clock();
    for(i=0; i<ARRAY_SIZE-1; i++) {
        int min_index = i;
        for(j=i+1; j<ARRAY_SIZE; j++) {
            if(array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
    end = clock();
    time_taken = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort took %f seconds to execute \n", time_taken);

    // Re-initialize array
    for(i=0; i<ARRAY_SIZE; i++) {
        array[i] = i;
    }

    // Benchmarking quick sort
    start = clock();
    quick_sort(array, 0, ARRAY_SIZE-1);
    end = clock();
    time_taken = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort took %f seconds to execute \n", time_taken);

    return 0;
}

void quick_sort(int* array, int low, int high) {
    if(low < high) {
        int pivot_index = partition(array, low, high);
        quick_sort(array, low, pivot_index-1);
        quick_sort(array, pivot_index+1, high);
    }
}

int partition(int* array, int low, int high) {
    int pivot = array[high];
    int i = (low-1);
    for(int j=low; j<=high-1; j++) {
        if(array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;
    return (i+1);
}