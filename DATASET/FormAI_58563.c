//FormAI DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define ITERATIONS 1000

int main() {
    int arr[MAX_SIZE];
    int sum = 0;

    // Fill the array with random numbers
    for(int i=0; i<MAX_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Measure the execution time of the loop
    clock_t t1 = clock();
    for(int i=0; i<ITERATIONS; i++) {
        for(int j=0; j<MAX_SIZE; j++) {
            sum += arr[j];
        }
    }
    clock_t t2 = clock();

    // Calculate the execution time in milliseconds
    double elapsed = (t2 - t1) * 1000.0 / CLOCKS_PER_SEC;

    // Print the results
    printf("Elapsed time: %.2f ms\n", elapsed);
    printf("Average time per iteration: %.2f us\n", elapsed * 1000.0 / ITERATIONS / MAX_SIZE);
    printf("Total sum: %d\n", sum);

    return 0;
}