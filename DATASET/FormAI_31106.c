//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int array[ARRAY_SIZE];
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;

    // Fill the array with random values
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Sort the array using bubble sort
    start = clock();
    for (i = 0; i < ARRAY_SIZE-1; i++) {
        for (j = 0; j < ARRAY_SIZE-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print the time taken for sorting
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for sort: %f seconds\n", cpu_time_used);

    return 0;
}