//FormAI DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

void allocate_memory(int **ptr, int size) {
    
    if (size > 0) {
        // Allocate memory for the current element
        *ptr = (int*) malloc(sizeof(int));

        // Verify if the allocation was successful
        if (*ptr == NULL) {
            printf("Error allocating memory!\n");
            exit(1);
        }

        // Read the value for the current element
        printf("Enter a value: ");
        scanf("%d", *ptr);

        // Call the function recursively for the next element
        allocate_memory(ptr + 1, size - 1);
    }
}

int main() {
    int *array = NULL;

    // Call the function to allocate memory for the array
    allocate_memory(&array, ARRAY_SIZE);

    // Print the array values
    printf("Array values:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", *(array + i));
    }

    // Free the allocated memory
    free(array);

    return 0;
}