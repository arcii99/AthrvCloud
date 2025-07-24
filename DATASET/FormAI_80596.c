//FormAI DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the constants
#define MAX_VALUE 10000
#define MIN_VALUE 1
#define ARRAY_SIZE 1000000

double get_execution_time(struct timespec start_time, struct timespec end_time) {
    return (double)(((end_time.tv_sec - start_time.tv_sec) * 1e9) + (end_time.tv_nsec - start_time.tv_nsec)) / 1e9;
}

void init_array(int* array) {
    // Initialize the array with random values between MIN_VALUE and MAX_VALUE
    for (int i=0; i<ARRAY_SIZE; i++)
        array[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
}

void print_array(int* array) {
    // Print the contents of the array
    for (int i=0; i<ARRAY_SIZE; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void bubble_sort(int* array) {
    // Sort the array using bubble sort algorithm
    for (int i=0; i<ARRAY_SIZE-1; i++) {
        for (int j=0; j<ARRAY_SIZE-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void quick_sort(int* array, int low, int high) {
    // Sort the array using quick sort algorithm
    if (low < high) {
        int pivot = array[high];
        int i = low-1;
        
        for (int j=low; j<high; j++) {
            if (array[j] <= pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        
        int temp = array[i+1];
        array[i+1] = array[high];
        array[high] = temp;
        
        int p = i+1;
        quick_sort(array, low, p-1);
        quick_sort(array, p+1, high);
    }
}

int main() {
    int array[ARRAY_SIZE];
    
    // Initialize the random number generator
    srand(time(NULL));
    
    // Initialize the array with random values
    init_array(array);
    
    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(array);
    
    // Sort the array using bubble sort and measure the execution time
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    bubble_sort(array);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double bubble_sort_time = get_execution_time(start_time, end_time);
    
    // Print the sorted array and the execution time
    printf("Bubble sorted array:\n");
    print_array(array);
    printf("Bubble sort execution time: %f sec\n", bubble_sort_time);
    
    // Initialize the array with random values
    init_array(array);
    
    // Sort the array using quick sort and measure the execution time
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    quick_sort(array, 0, ARRAY_SIZE-1);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double quick_sort_time = get_execution_time(start_time, end_time);
    
    // Print the sorted array and the execution time
    printf("Quick sorted array:\n");
    print_array(array);
    printf("Quick sort execution time: %f sec\n", quick_sort_time);
    
    return 0;
}