//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int main() {

    int i;
    int *arr = malloc(SIZE * sizeof(int)); // allocate memory for array

    // Populate array with random values
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    // Calculate the average value of the array
    int sum = 0;
    for (i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    double average = sum / SIZE;

    // Find the index of the maximum value in the array
    int max_index = 0;
    int max_value = arr[0];
    for (i = 1; i < SIZE; i++) {
        if (arr[i] > max_value) {
            max_index = i;
            max_value = arr[i];
        }
    }

    // Print results
    printf("Average value: %f\n", average);
    printf("Max value: %d\n", max_value);
    printf("Max index: %d\n", max_index);

    // Free the allocated memory
    free(arr);

    return 0;
}