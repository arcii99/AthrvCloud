//FormAI DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int *array = (int*)malloc(SIZE * sizeof(int)); // dynamically allocate memory for array
    int i, sum = 0;
    clock_t start, end;
    double cpu_time_used;

    // initialize array with random values between 1 and 100
    srand(time(NULL));
    for(i=0; i<SIZE; i++) {
        array[i] = rand() % 100 + 1;
    }

    // measure time taken to compute sum of array
    start = clock();
    for(i=0; i<SIZE; i++) {
        sum += array[i];
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sum of array: %d\nTime taken to compute sum: %f seconds\n", sum, cpu_time_used);

    free(array); // free dynamically allocated memory

    return 0;
}