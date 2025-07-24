//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITERATIONS 1000000000

int main() {
    clock_t start, end;
    double cpu_time_used;

    int sum = 0;
    start = clock();

    for (int i = 0; i < NUM_ITERATIONS; i++) {
        sum += i;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sum of the first %d numbers is %d\n", NUM_ITERATIONS, sum);
    printf("Time elapsed: %f seconds\n", cpu_time_used);

    return 0;
}