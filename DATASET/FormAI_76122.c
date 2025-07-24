//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Record the start time

    // Code that needs to be benchmarked
    int sum = 0;
    for (int i = 1; i <= 1000000000; i++) {
        sum += i;
    }

    end = clock(); // Record the end time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate CPU time used in seconds

    printf("Sum from 1 to %d is %d\n", 1000000000, sum);
    printf("CPU time used for the computation is %f seconds\n", cpu_time_used);

    return 0;
}