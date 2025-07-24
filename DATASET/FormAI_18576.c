//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Allocate memory for an array of 5 integers
    int *arr = (int*) malloc(5 * sizeof(int));

    // Check if memory was allocated successfully
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Fill the array with some values
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 2;
    }

    // Print out the array
    printf("Array values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Make some changes to the array
    arr[0] = 10;
    arr[4] = 20;

    // Print out the updated array
    printf("Updated array values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // De-allocate the memory
    free(arr);

    return 0;
}