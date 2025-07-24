//FormAI DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_SIZE 10000

int main() {
    int array[ARRAY_SIZE]; // initialize an array of size 10000
    int i;
    int sum = 0;
    clock_t start, end;
    double cpu_time_used;

    // populate the array with random numbers between 1 and 10000
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10000 + 1;
    }

    // measure the time it takes to sum all the elements in the array
    start = clock();
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    end = clock();

    // calculate the elapsed CPU time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // print the sum and elapsed time
    printf("Sum: %d\n", sum);
    printf("Elapsed time: %f seconds\n", cpu_time_used);

    return 0;
}