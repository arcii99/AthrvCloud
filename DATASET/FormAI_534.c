//FormAI DATASET v1.0 Category: Benchmarking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITERATIONS 1E9

// A function to benchmark the time required to generate a random number between 0-99.
void random_generator_benchmark() {
    clock_t start_time = clock();

    // Generate random numbers and discard them
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        int random_number = rand() % 100;
    }

    clock_t end_time = clock();
    double seconds_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Random number generator benchmark: %.3f seconds.\n", seconds_elapsed);
}

// A function to benchmark the time required to calculate the summation of a large array.
void sum_array_benchmark() {
    int array_size = 1E7;
    int* array = (int*)malloc(sizeof(int) * array_size);

    // Initialize array with random numbers between 0-99
    for (int i = 0; i < array_size; i++) {
        array[i] = rand() % 100;
    }

    clock_t start_time = clock();

    // Calculate sum of array
    int sum = 0;
    for (int i = 0; i < array_size; i++) {
        sum += array[i];
    }

    clock_t end_time = clock();
    double seconds_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Array summation benchmark: %.3f seconds. Sum of array: %d\n", seconds_elapsed, sum);

    free(array);
}

// A macro to easily print the results of a benchmark
#define PRINT_BENCHMARK_RESULT(benchmark_function) printf("----------------\n"); \
                                                   printf("Starting %s...\n", #benchmark_function); \
                                                   benchmark_function(); \
                                                   printf("Finished %s.\n", #benchmark_function);

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Benchmark the random number generator function
    PRINT_BENCHMARK_RESULT(random_generator_benchmark);

    // Benchmark the array summation function
    PRINT_BENCHMARK_RESULT(sum_array_benchmark);

    return 0;
}