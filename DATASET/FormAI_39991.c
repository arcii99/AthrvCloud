//FormAI DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define a pointer to an integer array
    int *arr;

    // Allocate memory for 10 integers
    arr = (int*)malloc(10 * sizeof(int));

    // Check if memory allocation is successful
    if (arr == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }

    // Initialize the array with some values
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 2;
    }

    // Print the array values
    printf("Initial Array Values:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Increase the array size to 15 integers
    arr = (int*)realloc(arr, 15 * sizeof(int));

    // Check if memory reallocation is successful
    if (arr == NULL) {
        printf("Memory reallocation failed!");
        exit(1);
    }

    // Initialize the new array elements
    for (int i = 10; i < 15; i++) {
        arr[i] = i * 3;
    }

    // Print the updated array values
    printf("Updated Array Values:\n");
    for (int i = 0; i < 15; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the memory allocated for the array
    free(arr);

    return 0;
}