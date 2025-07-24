//FormAI DATASET v1.0 Category: Benchmarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[1000000];
    long long sum = 0;
    clock_t start_t, end_t;
    double cpu_time_used;

    // Filling the array with random numbers
    for (int i = 0; i < 1000000; i++) {
        arr[i] = rand() % 100;
    }

    // Starting the timer
    start_t = clock();

    // Benchmarking code here
    for (int i = 0; i < 1000000; i++) {
        sum += arr[i];
    }

    // Ending the timer
    end_t = clock();

    cpu_time_used = ((double) (end_t - start_t)) / CLOCKS_PER_SEC;

    printf("The sum of array is: %lld\n", sum);
    printf("Time taken by CPU to sum the array is: %lf seconds", cpu_time_used);

    return 0;
}