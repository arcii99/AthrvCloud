//FormAI DATASET v1.0 Category: Benchmarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int *arr = calloc(SIZE, sizeof(int));  // allocate memory for array
    srand(time(NULL));  // seed random number generator
    
    clock_t start = clock();  // start timer
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;  // assign random values to array
    }
    clock_t end = clock();  // end timer
    
    double time_taken = ((double)(end - start))/CLOCKS_PER_SEC; // calculate execution time
    printf("Random array generation took %f seconds\n", time_taken);
    
    // summing array elements
    int sum = 0;
    start = clock();  // start timer
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    end = clock();  // end timer
    
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC; // calculate execution time
    printf("Sum of elements of the array is %d\n", sum);
    printf("Array summing took %f seconds\n", time_taken);
    
    free(arr);  // free memory allocated for array
    return 0;
}