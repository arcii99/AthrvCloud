//FormAI DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Allocate memory for an array of integers
    int* arr = (int*)malloc(10 * sizeof(int));

    // Check if allocation succeeded
    if (arr == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    // Fill the array with some values
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 2;
    }

    // Print the array
    printf("Array contents:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate memory for a larger array
    int* bigger_arr = (int*)realloc(arr, 20 * sizeof(int));

    // Check if reallocation succeeded
    if (bigger_arr == NULL) {
        printf("Failed to reallocate memory\n");
        free(arr);
        return 1;
    }

    // Fill the new part of the array with some values
    for (int i = 10; i < 20; i++) {
        bigger_arr[i] = i * 3;
    }

    // Print the array again
    printf("Enlarged array contents:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", bigger_arr[i]);
    }
    printf("\n");

    // Free the memory
    free(bigger_arr);

    return 0;
}