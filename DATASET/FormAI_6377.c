//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000
#define NUM_ITERATIONS 1000000

int main(void) {
    int array[ARRAY_SIZE];
    int i, j, tmp;
    clock_t start, end;
    double cpu_time;

    srand(time(NULL)); // Seed random number generator

    // Initialize array with random integers
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Sort the array using bubble sort
    start = clock(); // Start timer
    for (i = 0; i < NUM_ITERATIONS; i++) {
        for (j = 0; j < ARRAY_SIZE - 1; j++) {
            if (array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    end = clock(); // End timer
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print CPU time taken for sorting
    printf("CPU time used for sorting: %f seconds\n", cpu_time);

    return 0;
}