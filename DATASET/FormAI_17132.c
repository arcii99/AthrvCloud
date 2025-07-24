//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: enthusiastic
// Welcome to the amazing world of C programming!
// Are you ready to create a performance-critical component that will blow your mind?
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define NUM_ITERATIONS 100000

int main() {
    // Initialize array with random values
    int arr[ARRAY_SIZE];
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    // Time the execution of the operation
    clock_t start_time = clock();
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Perform the performance-critical component
        int sum = 0;
        for (int j = 0; j < ARRAY_SIZE; j++) {
            sum += arr[j];
        }
    }
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Print the results
    printf("Time taken to perform the performance-critical component: %f seconds\n", elapsed_time);
    printf("Average time per iteration: %f milliseconds\n", (elapsed_time / NUM_ITERATIONS) * 1000);

    return 0;
}