//FormAI DATASET v1.0 Category: Benchmarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000000

int main() {
    int i;
    double sum = 0;
    clock_t start, end; // for timing

    // allocate memory for large array
    double* nums = (double*) malloc(SIZE * sizeof(double));

    // initialize array with random values
    for (i = 0; i < SIZE; i++) {
        nums[i] = (double) rand() / RAND_MAX;
    }

    // benchmarking starts here
    start = clock(); // start timing

    // sum up all the values in the array
    for (i = 0; i < SIZE; i++) {
        sum += nums[i];
    }

    end = clock(); // end timing

    // print results
    printf("Sum: %lf\n", sum);
    printf("Time Elapsed: %lf seconds\n", (double)(end-start)/CLOCKS_PER_SEC);

    // free allocated memory
    free(nums);

    return 0;
}