//FormAI DATASET v1.0 Category: Benchmarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>

#define MAX 1000000000

int main() {
    clock_t start_time, end_time;
    double time_taken;

    start_time = clock();

    for(int i = 0; i < MAX; i++) {
        // Some expensive operation that we want to benchmark
        // In this case, we will just iterate through the loop
        int j = i;
    }

    end_time = clock();

    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken to complete operation: %f seconds\n", time_taken);

    return 0;
}