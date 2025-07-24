//FormAI DATASET v1.0 Category: Benchmarking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to perform the benchmarking
void benchmark(int iterations) {
    clock_t start, end;
    double cpu_time_used;

    // record the starting time
    start = clock();

    // perform the benchmarking loop
    for (int i = 0; i < iterations; i++) {
        // do some useless computation
        int j = i * 2;
        j = j * 3;
        j = j / 2;
    }

    // record the ending time
    end = clock();

    // calculate the CPU time used in seconds
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // output the results
    printf("Benchmark complete. %d iterations performed in %.5f seconds.\n", iterations, cpu_time_used);
}

int main() {
    int iterations;

    // get the number of iterations from the user
    printf("Enter the number of iterations to perform: ");
    scanf("%d", &iterations);

    // perform the benchmarking
    benchmark(iterations);

    return 0;
}