//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 100000
#define NUM_ITERATIONS 1000000

int a[ARRAY_SIZE], b[ARRAY_SIZE], c[ARRAY_SIZE];

void initialize_arrays() {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        a[i] = rand() % 1000;
        b[i] = rand() % 1000;
    }
}

void multiply_arrays() {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        c[i] = a[i] * b[i];
    }
}

int main() {
    clock_t start_time, end_time;
    double total_time;
    int i;

    // Initialize arrays with random values
    initialize_arrays();

    // Benchmark multiplication function for NUM_ITERATIONS iterations
    start_time = clock();
    for (i = 0; i < NUM_ITERATIONS; i++) {
        multiply_arrays();
    }
    end_time = clock();

    // Calculate total time taken
    total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Print results
    printf("Integer multiplication benchmark results:\n");
    printf("Array size: %d\n", ARRAY_SIZE);
    printf("Number of iterations: %d\n", NUM_ITERATIONS);
    printf("Total time taken: %lf seconds\n", total_time);
    printf("Average time per iteration: %lf seconds\n", total_time / NUM_ITERATIONS);

    return 0;
}