//FormAI DATASET v1.0 Category: Benchmarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {

    int a[SIZE];
    clock_t start, end;
    double time_taken;

    // Populating the array with random integers
    for (int i = 0; i < SIZE; ++i) {
        a[i] = rand();
    }

    // Starting the benchmarking timer
    start = clock();

    // Your unique benchmarking logic goes here...
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += a[i];
    }

    // Ending the benchmarking timer
    end = clock();

    // Calculating the time taken by the code
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sum of array elements: %d\n", sum);
    printf("Time taken by the program: %f seconds\n", time_taken);

    return 0;
}