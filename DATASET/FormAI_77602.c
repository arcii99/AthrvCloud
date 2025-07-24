//FormAI DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    // Declare variables
    clock_t start_time, end_time;
    double total_time;
    int i, sum1 = 0, sum2 = 0;
    int data_array[ARRAY_SIZE];

    // Initialize random number generator
    srand(time(NULL));

    // Fill data array with random integers
    for (i = 0; i < ARRAY_SIZE; i++) {
        data_array[i] = rand() % 100;
    }

    // Loop through data array and calculate sum1
    start_time = clock();
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum1 += data_array[i];
    }
    end_time = clock();
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sum1: %d\n", sum1);
    printf("Time taken for sum1: %f seconds\n", total_time);

    // Loop through data array in reverse order and calculate sum2
    start_time = clock();
    for (i = ARRAY_SIZE - 1; i >= 0; i--) {
        sum2 += data_array[i];
    }
    end_time = clock();
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sum2: %d\n", sum2);
    printf("Time taken for sum2: %f seconds\n", total_time);

    return 0;
}