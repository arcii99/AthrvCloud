//FormAI DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <time.h>
#define NUM_LOOPS 1000000000

int main() {
    clock_t start, end;
    double cpu_time_used;

    printf("Starting benchmark...\n");
    start = clock();

    int i, sum = 0;
    for (i = 0; i < NUM_LOOPS; i++) {
        sum += i;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sum: %d\n", sum);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}