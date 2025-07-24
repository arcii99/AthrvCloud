//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int array[ARRAY_SIZE], i, j;
    clock_t t1, t2;

    // Fill the array with random integers between 0 and 100
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 101;
    }

    // Start the timer
    t1 = clock();

    // Sort the array using insertion sort
    for (i = 1; i < ARRAY_SIZE; i++) {
        for (j = i; j > 0 && array[j-1] > array[j]; j--) {
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
        }
    }

    // Stop the timer and print the execution time
    t2 = clock();
    printf("Execution time: %.2f seconds\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    return 0;
}