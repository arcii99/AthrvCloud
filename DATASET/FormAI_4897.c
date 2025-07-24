//FormAI DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform the benchmarking
void benchmark(int arr[], int n) {
    int sum = 0;
    clock_t start = clock();
    
    // Summing up the elements of the array
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Sum: %d\n", sum);
    printf("Time taken: %f seconds\n", time_taken);
}

int main() {
    // Initializing array of 10 million integers
    int n = 10000000;
    int *arr = (int*)malloc(n * sizeof(int)); 
    
    srand(time(NULL));
    
    // Filling array with random integers between 1 and 100
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
    
    // Performing benchmarking with the array
    benchmark(arr, n);
    
    // Freeing the allocated memory
    free(arr);
    
    return 0;
}