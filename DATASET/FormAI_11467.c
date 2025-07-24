//FormAI DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an array of integers with a size of 5
    int *arr = (int*)malloc(5 * sizeof(int));

    // Check if the allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    else {
        printf("Memory was allocated successfully. \n");
    }

    // Fill the array with some random values
    arr[0] = 23;
    arr[1] = 53;
    arr[2] = 67;
    arr[3] = 18;
    arr[4] = 81;

    // Print the values of the array
    printf("Array values: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Change the size of the array to 10
    arr = (int*)realloc(arr, 10 * sizeof(int));

    if (arr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    // Fill the rest of the array with some new values
    arr[5] = 13;
    arr[6] = 47;
    arr[7] = 29;
    arr[8] = 76;
    arr[9] = 92;

    // Print the values of the array again
    printf("New array values: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}