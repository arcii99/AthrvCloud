//FormAI DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Allocate memory for an array of 10 integers
    int* arr = (int*)malloc(10 * sizeof(int));

    // Set random values for each element in the array
    for (int i = 0; i < 10; i++) {
        *(arr + i) = rand() % 100;
    }

    // Print the values in the array
    printf("Values in the array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(arr + i));
    }

    // Reallocate memory for an array of 20 integers
    int* arr2 = (int*)realloc(arr, 20 * sizeof(int));
    if (arr2 == NULL) {
        printf("Error: reallocation of memory failed\n");
        exit(1);
    }
    else {
        arr = arr2;
    }

    // Add more random values to the array
    for (int i = 10; i < 20; i++) {
        *(arr + i) = rand() % 100;
    }

    // Print the values in the array
    printf("\n\nValues in the array after reallocation:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", *(arr + i));
    }

    // Free the allocated memory
    free(arr);

    return 0;
}