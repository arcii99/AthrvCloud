//FormAI DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {

    // Declare and initialize arrays
    int array1[ARRAY_SIZE], array2[ARRAY_SIZE];

    srand(time(NULL)); // Seed random number generator

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    // Calculate sum of arrays using loop
    clock_t start1 = clock();
    long sum1 = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum1 += array1[i] + array2[i];
    }

    clock_t end1 = clock();
    double time1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;

    // Calculate sum of arrays using pointer arithmetic
    clock_t start2 = clock();
    long sum2 = 0;

    int *ptr1 = array1;
    int *ptr2 = array2;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum2 += *ptr1 + *ptr2;
        ptr1++;
        ptr2++;
    }

    clock_t end2 = clock();
    double time2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;

    // Print results
    printf("Sum of arrays using loop: %ld\n", sum1);
    printf("Time taken using loop: %f seconds\n", time1);
    printf("Sum of arrays using pointer arithmetic: %ld\n", sum2);
    printf("Time taken using pointer arithmetic: %f seconds\n", time2);

    return 0;
}