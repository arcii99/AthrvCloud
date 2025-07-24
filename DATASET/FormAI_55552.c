//FormAI DATASET v1.0 Category: Benchmarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int array[ARRAY_SIZE];
    long long sum = 0;

    // Fill array with random numbers
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Benchmark loop
    clock_t start_time = clock();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    clock_t end_time = clock();

    // Calculate time and print results
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sum of array: %lld\n", sum);
    printf("Time taken: %lf seconds\n", time_taken);

    return 0;
}