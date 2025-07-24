//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n) { // Function to perform selection sort
    int i, j, min_index, temp;
    
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void bubble_sort(int arr[], int n) { // Function to perform bubble sort
    int i, j, temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr_size = 10000;
    int arr1[arr_size], arr2[arr_size]; // Initializing two arrays
    int i;
    
    srand(time(NULL));
    for (i = 0; i < arr_size; i++) { // Populating the arrays with random integers
        arr1[i] = rand();
        arr2[i] = arr1[i];
    }
    
    clock_t start = clock();
    selection_sort(arr1, arr_size); // Timing the selection sort algorithm
    clock_t end = clock();
    
    double selection_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for selection sort: %f seconds\n", selection_time);
    
    start = clock();
    bubble_sort(arr2, arr_size); // Timing the bubble sort algorithm
    end = clock();
    
    double bubble_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort: %f seconds\n", bubble_time);
    
    if (bubble_time < selection_time) { // Determining which sorting algorithm is faster
        printf("Bubble sort is faster than selection sort.\n");
    } else {
        printf("Selection sort is faster than bubble sort.\n");
    }
    
    return 0;
}