//FormAI DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to generate random values between 1 and 1000
int get_random_value() {
    return rand() % 1000 + 1;
}

int main() {
    srand(time(NULL)); // Initializing random seed

    int i, j;
    int array[ARRAY_SIZE];

    // Filling the array with random values
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = get_random_value();
    }

    // Benchmarking the time taken for a bubble sort
    clock_t start = clock();
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j < ARRAY_SIZE - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swapping the elements if they are out of order
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    clock_t end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Outputting the sorted array and the time taken
    printf("Sorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\nTime taken for bubble sort: %f seconds\n", time_taken);

    return 0;
}