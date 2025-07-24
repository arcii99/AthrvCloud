//FormAI DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int i;
    double total_time;
    clock_t start, end;
    int array[SIZE];

    // initialize the array with random numbers
    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // start the timer
    start = clock();

    // perform some CPU intensive task on the array
    int sum = 0;
    for (i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    // end the timer
    end = clock();

    // calculate the total time taken
    total_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // print the result and the time taken
    printf("Sum of the array: %d\n", sum);
    printf("Time taken: %f seconds\n", total_time);

    return 0;
}