//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int *array = (int *) malloc(sizeof(int) * SIZE);
    int i, j, n;
    time_t t;

    // Seed the random number generator
    srand((unsigned) time(&t));

    // Populate the array with random numbers
    for (n = 0; n < SIZE; n++)
        array[n] = rand() % 1000;

    // Sort the array using bubble sort
    for (i = 0; i < SIZE - 1; i++)
        for (j = 0; j < SIZE - i - 1; j++)
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }

    // Print the sorted array
    for (n = 0; n < SIZE; n++)
        printf("%d ", array[n]);

    free(array);
    return 0;
}