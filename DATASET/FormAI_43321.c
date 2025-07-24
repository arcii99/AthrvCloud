//FormAI DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;

    printf("Welcome to the C Benchmarking Example Program!\n");

    // Perform some test calculation (sum of first 100,000 integers)
    start = clock();

    long sum = 0;
    for (long i = 1; i <= 100000; i++)
    {
        sum += i;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Calculated the sum of first 100,000 integers: %ld\n", sum);
    printf("CPU time used: %f seconds\n", cpu_time_used);

    // Now, benchmark the same calculation with a larger number of iterations
    int num_iterations = 50000000;

    printf("Benchmarking the sum of first %d integers...\n", num_iterations);

    start = clock();

    long long total_sum = 0;
    for (int i = 1; i <= num_iterations; i++)
    {
        total_sum += i;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Total sum of first %d integers: %lld\n", num_iterations, total_sum);
    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}