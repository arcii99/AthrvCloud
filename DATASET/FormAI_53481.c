//FormAI DATASET v1.0 Category: Benchmarking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_iterations = 1000000000;
    clock_t start_time, end_time;
    double time_elapsed;

    // Benchmarking function
    start_time = clock();
    for (int i = 0; i < num_iterations; i++) {
        // Do some computation here
    }
    end_time = clock();

    time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time elapsed: %f seconds\n", time_elapsed);

    return 0;
}