//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int i;
    clock_t start, end;
    double cpu_time_used;

    // Initializing array of random integers
    int arr[ARRAY_SIZE];
    for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Benchmarking sorting algorithm
    start = clock();
    // Code for sorting algorithm goes here
    end = clock();

    // Calculating time taken by the sorting algorithm
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}