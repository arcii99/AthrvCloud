//FormAI DATASET v1.0 Category: Benchmarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the number of iterations for the benchmark */
#define ITERATIONS 10000

/* Define the function to be benchmarked */
int sum_array(int *arr, int size) {
    int sum = 0;
    for (int i=0; i<size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    /* Seed the random number generator */
    srand(time(NULL));

    /* Allocate memory for the array */
    int *arr = (int*) malloc(sizeof(int) * ITERATIONS);

    /* Initialize the array with random values */
    for (int i=0; i<ITERATIONS; i++) {
        arr[i] = rand() % 100;
    }

    /* Benchmark the function */
    clock_t start_time = clock();
    int result = sum_array(arr, ITERATIONS);
    clock_t end_time = clock();
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    /* Print the result and the time taken */
    printf("Sum of array: %d\n", result);
    printf("Time taken: %f seconds\n", time_taken);

    /* Free the allocated memory */
    free(arr);

    return 0;
}