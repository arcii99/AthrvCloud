//FormAI DATASET v1.0 Category: Benchmarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    // Declare variables
    clock_t start_t, end_t;
    double total_t;
    int i, j;
    int temp;
    int array[ARRAY_SIZE];

    // Fill the array with random integers
    srand(time(0));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Start the timer
    start_t = clock();

    // Bubble sort algorithm
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Stop the timer
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    // Print out the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print out the time taken by the algorithm
    printf("Time taken by bubble sort: %f seconds\n", total_t);

    return 0;
}