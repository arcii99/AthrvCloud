//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000000

int main() {
    int *arr = (int *) malloc(sizeof(int) * SIZE);
    clock_t start, end;
    double cpu_time_used;
    int sum = 0;

    // initialize array with random values
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // calculate sum of array elements
    start = clock();
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // print output
    printf("Sum of array elements: %d\n", sum);
    printf("Time taken to calculate sum: %f seconds\n", cpu_time_used);

    // free memory
    free(arr);

    return 0;
}