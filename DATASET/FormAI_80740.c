//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int array[SIZE];
    int i, j, tmp;

    // Populate array with random values
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000 + 1;
    }

    // Sort the array using bubble sort algorithm
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (array[j] > array[j+1]) {
                // Swap elements
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }

    // Print the sorted array
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}