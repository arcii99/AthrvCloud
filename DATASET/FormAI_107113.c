//FormAI DATASET v1.0 Category: Benchmarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 10000000
#define LOOP_COUNT 10

int main(void)
{
    clock_t start, end;

    // allocate memory for two arrays
    int *arr1 = malloc(sizeof(int) * ARR_SIZE);
    int *arr2 = malloc(sizeof(int) * ARR_SIZE);

    // initialize the arrays with random values
    for (int i = 0; i < ARR_SIZE; i++) {
        arr1[i] = rand();
        arr2[i] = rand();
    }

    // start the benchmarking loop
    for (int i = 0; i < LOOP_COUNT; i++) {
        start = clock();

        // perform the benchmarked operation
        for (int j = 0; j < ARR_SIZE; j++) {
            arr1[j] += arr2[j];
        }

        end = clock();

        // calculate and print the elapsed time
        double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Loop %d took %f seconds.\n", i+1, elapsed_time);

        // reset the values in arr1 to the initial random values
        for (int j = 0; j < ARR_SIZE; j++) {
            arr1[j] = rand();
        }
    }

    // free the allocated memory
    free(arr1);
    free(arr2);

    return 0;
}