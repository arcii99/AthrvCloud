//FormAI DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 1000000

int main() {
    srand(time(NULL));
    
    // Configurable options
    int num_iterations = 1000;
    int num_tests = 5;
    int array_size_increment = 100000;
    
    // Initialize arrays to be sorted
    int *array1 = (int*) malloc(ARR_SIZE * sizeof(int));
    int *array2 = (int*) malloc(ARR_SIZE * sizeof(int));
    
    // Generate random numbers for array1
    for (int i = 0; i < ARR_SIZE; i++) {
        array1[i] = rand() % 1000;
    }
    
    printf("Starting benchmarking...\n");
    printf("Iterations: %d\n", num_iterations);
    printf("Number of Tests: %d\n", num_tests);
    printf("Array Size Increment: %d\n", array_size_increment);
    
    for (int i = 0; i < num_tests; i++) {
        printf("\nTest #%d:\n", i+1);
        
        int array_size = array_size_increment * (i+1);
        printf("Array Size: %d\n", array_size);
        
        // Copy array1 to array2
        for (int j = 0; j < array_size; j++) {
            array2[j] = array1[j];
        }
        
        // Test Bubble Sort
        double bubble_sort_time = 0;
        for (int j = 0; j < num_iterations; j++) {
            clock_t start_time = clock();
            for (int k = 0; k < array_size-1; k++) {
                for (int l = 0; l < array_size-k-1; l++) {
                    if (array2[l] > array2[l+1]) {
                        int temp = array2[l];
                        array2[l] = array2[l+1];
                        array2[l+1] = temp;
                    }
                }
            }
            clock_t end_time = clock();
            double time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
            bubble_sort_time += time_elapsed;
        }
        bubble_sort_time /= num_iterations;
        printf("Bubble Sort Time: %f seconds\n", bubble_sort_time);
        
        // Copy array1 to array2
        for (int j = 0; j < array_size; j++) {
            array2[j] = array1[j];
        }
        
        // Test Quick Sort
        double quick_sort_time = 0;
        for (int j = 0; j < num_iterations; j++) {
            clock_t start_time = clock();
            quick_sort(array2, 0, array_size-1);
            clock_t end_time = clock();
            double time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
            quick_sort_time += time_elapsed;
        }
        quick_sort_time /= num_iterations;
        printf("Quick Sort Time: %f seconds\n", quick_sort_time);
    }

    free(array1);
    free(array2);
    
    return 0;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}