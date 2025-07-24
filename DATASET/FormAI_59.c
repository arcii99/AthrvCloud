//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define RAND_RANGE 1000

int main() {
    int array[ARRAY_SIZE];
    int i, j, temp;
    time_t start, end;
    double time_taken;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize array with random numbers
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % RAND_RANGE;
    }

    // Time the sorting algorithm
    time(&start);
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    time(&end);
    time_taken = difftime(end, start);

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print the time taken to sort the array
    printf("Time taken: %.2f seconds\n", time_taken);

    return 0;
}