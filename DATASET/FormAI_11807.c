//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define NUM_ITERATIONS 100000
#define RANDOM_MAX 100

int main(void) {
    int i, j, temp;
    int original_array[ARRAY_SIZE];
    int sorted_array[ARRAY_SIZE];

    // initialize original array with random integers
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        original_array[i] = rand() % RANDOM_MAX;
    }

    // copy original array to sorted array
    memcpy(sorted_array, original_array, sizeof(original_array));

    // print original array
    printf("Original Array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", original_array[i]);
    }
    printf("\n");

    // sort sorted array using bubble sort algorithm
    clock_t start_time = clock();
    for (i = 0; i < NUM_ITERATIONS; i++) {
        for (j = 0; j < ARRAY_SIZE - 1; j++) {
            if (sorted_array[j] > sorted_array[j+1]) {
                temp = sorted_array[j+1];
                sorted_array[j+1] = sorted_array[j];
                sorted_array[j] = temp;
            }
        }
    }
    clock_t end_time = clock();

    // print sorted array
    printf("Sorted Array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    // calculate and print elapsed time for sorting algorithm
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Elapsed time for sorting algorithm: %f seconds\n", elapsed_time);

    return 0;
}