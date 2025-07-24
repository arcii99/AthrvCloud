//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000

int main() {
    int *arr = malloc(ARRAY_SIZE * sizeof(int)); // allocate memory for the array
    if (arr == NULL) { // check if allocation was successful
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(NULL)); // seed the random number generator

    // initialize the array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    int sum = 0;

    // calculate the sum of all even numbers in the array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }

    printf("The sum of all even numbers in the array is %d.\n", sum);

    free(arr); // free the memory used by the array

    return 0;
}