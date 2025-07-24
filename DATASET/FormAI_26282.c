//FormAI DATASET v1.0 Category: Benchmarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int array[ARRAY_SIZE];

    // initialize array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // calculate sum of array using loop
    clock_t start_time = clock(); // start timer
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    printf("Sum of array using loop = %d\n", sum);
    double loop_time = ((double) (clock() - start_time)) / CLOCKS_PER_SEC;

    // calculate sum of array using pointer arithmetic
    start_time = clock(); // reset timer
    sum = 0;
    int *ptr = array;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += *(ptr++);
    }
    printf("Sum of array using pointer arithmetic = %d\n", sum);
    double ptr_time = ((double) (clock() - start_time)) / CLOCKS_PER_SEC;

    // calculate sum of array using memset and memcpy
    start_time = clock(); // reset timer
    sum = 0;
    int temp[ARRAY_SIZE];
    memset(temp, 0, ARRAY_SIZE * sizeof(int));
    memcpy(temp, array, ARRAY_SIZE * sizeof(int));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += temp[i];
    }
    printf("Sum of array using memset and memcpy = %d\n", sum);
    double memcpy_time = ((double) (clock() - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken using loop = %f seconds\n", loop_time);
    printf("Time taken using pointer arithmetic = %f seconds\n", ptr_time);
    printf("Time taken using memset and memcpy = %f seconds\n", memcpy_time);
    return 0;
}