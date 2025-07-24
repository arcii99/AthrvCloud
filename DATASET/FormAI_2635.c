//FormAI DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <time.h>

int main() {
    printf("Welcome to the benchmarking program!\n");

    clock_t start, end;
    int num_iterations = 1000000000;
    double avg_time_elapsed;

    // code to be benchmarked - start
    int sum = 0;
    for (int i = 0; i < num_iterations; i++) {
        sum += i;
    }
    // code to be benchmarked - end

    // benchmarking code - start
    printf("Starting benchmark...\n");
    start = clock();
    for (int i = 0; i < num_iterations; i++) {
        sum += i;
    }
    end = clock();
    printf("Benchmark completed!\n");

    avg_time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC / num_iterations;

    printf("Average time elapsed for one iteration: %f seconds\n", avg_time_elapsed);
    printf("Total time elapsed for %d iterations: %f seconds\n", num_iterations, (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}