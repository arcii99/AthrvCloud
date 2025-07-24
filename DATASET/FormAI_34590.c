//FormAI DATASET v1.0 Category: Benchmarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the number of iterations for the benchmark */
#define BENCHMARK_ITERATIONS 1000000000

int main() {
    /* Initialize variables */
    int i, j;
    double result = 0;
    clock_t start_time, end_time;

    /* Loop through the benchmark iterations and time the calculations */
    start_time = clock();
    for (i=1; i<=BENCHMARK_ITERATIONS; i++) {
        for (j=1; j<=i; j++) {
            result += (double) j / (double) (i*i);
        }
    }
    end_time = clock();

    /* Calculate the time taken for the benchmark and output the result */
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Benchmark took %f seconds to run.\n", time_taken);

    /* Output the result of the benchmark calculation */
    printf("Result of benchmark calculation: %f\n", result);

    return 0;
}