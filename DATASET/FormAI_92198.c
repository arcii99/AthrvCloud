//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000000

int main() {
    int *array = (int*) malloc(SIZE * sizeof(int)); // allocate memory for array
    if (array == NULL) {
        printf("Failed to allocate memory!");
        return 1;
    }

    srand(time(NULL)); // seed the random number generator

    // initialize the array with random integers between 0 and 999
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }

    int sum = 0;

    // calculate the sum of the array using a for loop
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    printf("The sum of the array is: %d\n", sum);

    free(array); // free the allocated memory

    return 0;
}