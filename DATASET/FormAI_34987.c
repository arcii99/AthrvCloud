//FormAI DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array_size = 1000000; // Size of array
    int* arr = (int*) malloc(array_size * sizeof(int)); // Dynamically allocate memory for the array

    srand(time(NULL)); // Seed the random number generator
    for(int i=0; i<array_size; i++) {
        arr[i] = rand(); // Fill the array with random numbers
    }

    // Start benchmarking
    clock_t start = clock(); // Record the starting time
    for(int i=0; i<array_size; i++) {
        arr[i] = arr[i] * 2; // Multiply each element of the array by 2
    }
    // End benchmarking
    clock_t end = clock(); // Record the ending time

    double time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate the time taken

    printf("Time taken to double each element of the array: %f seconds\n", time_used);

    free(arr); // Free the allocated memory

    return 0;
}