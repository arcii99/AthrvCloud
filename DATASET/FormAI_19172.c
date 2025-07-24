//FormAI DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int main() {
    int arr[SIZE];
    int sum = 0;
    double time_taken;

    // initialize random seed
    srand(time(NULL));

    // fill array with random numbers
    for (int i=0; i<SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // start time measurement
    clock_t t1 = clock();

    // loop through array, calculate and add up sum of elements
    for (int i=0; i<SIZE; i++) {
        sum += arr[i];
    }

    // end time measurement
    clock_t t2 = clock();

    // calculate time taken for loop
    time_taken = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

    // output results
    printf("Sum of array elements: %d\n", sum);
    printf("Time taken for loop: %f seconds", time_taken);

    return 0;
}