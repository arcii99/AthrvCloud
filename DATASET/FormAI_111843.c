//FormAI DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer array of size 5
    int *arr = (int*) malloc(5 * sizeof(int));

    // Check if memory was allocated successfully
    if (arr == NULL) {
        printf("Error: Memory could not be allocated.\n");
        return -1;
    }

    // Initialize the array with some values
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 2;
    }

    // Print the array
    printf("Array values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deallocate the memory for the array
    free(arr);

    printf("Memory deallocated successfully.\n");

    return 0;
}