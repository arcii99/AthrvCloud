//FormAI DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int array[ARRAY_SIZE];
    int i, sum = 0;
    clock_t start, end;
    double cpu_time_used;

    // Initialize array with random values
    for(i=0; i<ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Start benchmarking
    printf("Starting benchmark...\n");
    start = clock();

    // Perform some heavy computations
    for(i=0; i<ARRAY_SIZE; i++) {
        sum += array[i];
    }
    printf("Sum of array elements is: %d\n", sum);

    // End benchmarking
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds\n", cpu_time_used);

    return 0;
}