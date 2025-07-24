//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    long long num, sum = 0;
    clock_t start_time, end_time;
    double time_elapsed;

    // Get user input
    printf("Enter a number to calculate sum from 1 to that number: ");
    scanf("%lld", &num);

    // Start measuring time
    start_time = clock();

    // Calculate sum
    for (long long i = 1; i <= num; i++) {
        sum += i;
    }

    // End measuring time
    end_time = clock();
    time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Print result and execution time
    printf("The sum from 1 to %lld is %lld\n", num, sum);
    printf("Execution time: %.5f seconds\n", time_elapsed);

    return 0;
}