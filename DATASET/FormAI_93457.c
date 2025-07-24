//FormAI DATASET v1.0 Category: Benchmarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000
#define ACCURACY 1000000000

int main() {
    int array[ARRAY_SIZE];
    int sum = 0;
    int i, j;
    double time_taken;
    clock_t start, end;

    // Fill the array with random values
    srand(time(0));
    for(i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Benchmark the summing of the array elements
    start = clock();
    for(i = 0; i < ACCURACY; i++) {
        sum = 0;
        for(j = 0; j < ARRAY_SIZE; j++) {
            sum += array[j];
        }
    }
    end = clock();

    // Calculate the time taken
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output the results
    printf("Sum of array elements: %d\n", sum);
    printf("Time taken to sum %d arrays of size %d: %f seconds\n", ACCURACY, ARRAY_SIZE, time_taken);

    return 0;
}