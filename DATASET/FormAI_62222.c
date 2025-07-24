//FormAI DATASET v1.0 Category: Memory management ; Style: content
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5; // Number of elements in the array
    int *array = (int *) malloc(n * sizeof(int)); // Allocate memory for the array

    if (array == NULL) { // Check if the allocation was successful
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        array[i] = i * 2; // Assign values to the array
    }

    printf("Original array\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]); // Print the original array
    }

    printf("\n");

    n = 10; // Increase the number of elements in the array
    int *new_array = (int *) realloc(array, n * sizeof(int)); // Reallocate memory for the array

    if (new_array == NULL) { // Check if the reallocation was successful
        printf("Memory reallocation failed\n");
        free(array);
        return 1;
    }

    for (int i = 5; i < n; i++) {
        new_array[i] = i * 2; // Assign values to the new elements in the array
    }

    printf("New array\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", new_array[i]); // Print the new array
    }

    printf("\n");

    free(new_array); // Free the memory allocated for the array

    return 0;
}