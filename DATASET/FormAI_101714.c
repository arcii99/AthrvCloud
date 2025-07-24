//FormAI DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITERATIONS 100000000

/* This program benchmarks the performance of the C standard library's rand() function. */

int main()
{
    srand(time(NULL)); // Seed the random number generator with current time
    int sum = 0;
    clock_t startTime, endTime;

    startTime = clock(); // Record the start time of the benchmark

    for (int i = 0; i < NUM_ITERATIONS; i++)
    {
        sum += rand(); // Generate a random number and add it to the sum
    }

    endTime = clock(); // Record the end time of the benchmark

    double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("Time taken: %.6f seconds\n", elapsedTime);
    printf("Average rand(): %f\n", (double)sum / NUM_ITERATIONS);

    return 0;
}