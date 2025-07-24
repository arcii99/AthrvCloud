//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // configurable array size
#define LOOP_ITERATIONS 10000 // configurable number of loop iterations

int main() {
    double *array;
    array = (double *) malloc(ARRAY_SIZE * sizeof(double)); // allocate memory for the array
    if (array == NULL) {
        printf("Error: could not allocate memory for the array\n");
        return 1;
    }

    srand(time(NULL)); // initialize the random number generator

    // initialize the array with random values between -1.0 and 1.0
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = ((double) rand() / (double) RAND_MAX) * 2.0 - 1.0;
    }

    clock_t start = clock();

    // perform a simple calculation on the array for a configurable number of loop iterations
    for (int j = 0; j < LOOP_ITERATIONS; j++) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = sqrt(array[i] * array[i] + 1.0);
        }
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Calculation took %f seconds\n", seconds);

    free(array); // free the memory allocated for the array

    return 0;
}