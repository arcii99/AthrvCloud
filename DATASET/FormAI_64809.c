//FormAI DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform the benchmarking
void benchmark(int n) {
    int i, sum = 0;
    clock_t start, end;
    double cpu_time_used;

    // Start the clock
    start = clock();

    // Perform a medieval calculation
    for (i = 1; i <= n; i++) {
        sum += i;
    }

    // End the clock
    end = clock();

    // Calculate the CPU time used
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Output the results
    printf("Sum of numbers from 1 to %d is %d\n", n, sum);
    printf("CPU time used: %f seconds\n", cpu_time_used);
}

// Main function
int main() {
    // Run the benchmarking for different values of n
    benchmark(1000);
    benchmark(100000);
    benchmark(10000000);

    return 0;
}