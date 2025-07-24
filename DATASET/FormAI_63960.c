//FormAI DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main(void) {
    int numbers[ARRAY_SIZE];
    clock_t t1, t2;

    // Fill the array with random numbers
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % 1000;
    }

    // Start the benchmark
    t1 = clock();

    // Perform some operation on the array
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += numbers[i];
    }

    // End the benchmark
    t2 = clock();
    double time_taken = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

    printf("Sum of array: %d\n", sum);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}