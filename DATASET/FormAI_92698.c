//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // Size of the array
#define ITERATIONS 100000 // Number of iterations

int main() {
    int i, j, temp;
    int array[ARRAY_SIZE];

    // Generate random numbers and assign them to the array
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Perform bubble sort and time it
    clock_t t1, t2;
    t1 = clock();
    for (i = 0; i < ITERATIONS; i++) {
        for (j = 0; j < ARRAY_SIZE - 1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    t2 = clock();

    // Calculate time taken for one iteration and print it
    double time_taken = ((double)(t2 - t1) / CLOCKS_PER_SEC) / ITERATIONS;
    printf("Time taken per iteration: %f seconds\n", time_taken);

    return 0;
}