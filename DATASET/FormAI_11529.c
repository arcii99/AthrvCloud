//FormAI DATASET v1.0 Category: Benchmarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define REP 1000000

// A simple function that returns the median of two integers
int median(int a, int b) {
    return (a + b) / 2;
}

// A benchmark function that measures the time taken to compute the median
void benchmark() {
    int i, j, med;

    // Measure the time taken to compute the median using a loop
    clock_t start = clock();
    for (i = 0; i < REP; i++) {
        for (j = 0; j < REP; j++) {
            med = median(i, j);
        }
    }
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
}

int main() {
    // Invoke the benchmark function to measure the time taken to compute the median
    benchmark();

    return 0;
}