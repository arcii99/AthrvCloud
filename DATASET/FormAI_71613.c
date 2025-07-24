//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000000
#define MAX_RANDOM_NUM 100
#define ITERATIONS 1000

int main() {
    int array[MAX_ARRAY_SIZE];
    int sum = 0;

    srand(time(0)); // Seed the random number generator

    // Fill array with random numbers
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        array[i] = rand() % MAX_RANDOM_NUM;
    }

    clock_t start = clock(); // Start time measurement

    // Perform the summing operation multiple times
    for (int j = 0; j < ITERATIONS; j++) {
        for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
            sum += array[i];
        }
    }

    clock_t end = clock(); // End time measurement

    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate time taken
    printf("Sum: %d\n", sum);
    printf("Time taken: %lf seconds\n", time_taken);

    return 0;
}