//FormAI DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000 // Size of array
#define TRIALS 10 // Number of times to run the test

// Function to initialize array with random integers
void init_array(int *arr, int size) {
    srand(time(NULL)); // Initialize random seed
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1; // Generate random integer between 1 and 100
    }
}

// Function to perform benchmark test
void benchmark(int *arr, int size) {
    int sum = 0;
    clock_t start_time = clock(); // Get start time
    for (int i = 0; i < size; i++) {
        sum += arr[i]; // Add array element to sum
    }
    double time_taken = (double)(clock() - start_time) / CLOCKS_PER_SEC; // Calculate time taken
    printf("Sum of array elements: %d\n", sum);
    printf("Time taken: %f seconds\n", time_taken);
}

int main() {
    int arr[SIZE];
    init_array(arr, SIZE);
    printf("Running benchmark test %d times...\n", TRIALS);
    for (int i = 0; i < TRIALS; i++) {
        printf("Test %d:\n", i+1);
        benchmark(arr, SIZE);
    }
    return 0;
}