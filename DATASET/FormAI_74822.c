//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main(void) {
    int array[ARRAY_SIZE];
    int i, j;

    // Populate the array with random integers
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand();
    }

    // Sort the array using insertion sort algorithm
    for (i = 1; i < ARRAY_SIZE; i++) {
        int key = array[i];
        for (j = i - 1; j >= 0 && array[j] > key; j--) {
            array[j + 1] = array[j];
        }
        array[j + 1] = key;
    }

    // Display the first 10 numbers of the sorted array
    for (i = 0; i < 10; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}