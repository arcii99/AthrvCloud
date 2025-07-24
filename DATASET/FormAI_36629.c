//FormAI DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define number of elements in array
#define ARRAY_SIZE 10

int main() {
    // Allocate memory for array of integers
    int* integer_array = (int*)malloc(ARRAY_SIZE * sizeof(int));

    // Check if memory allocated successfully
    if(integer_array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Memory allocated successfully for integer array of size %d\n\n", ARRAY_SIZE);

    // Initialize values in integer array
    for(int i = 0; i < ARRAY_SIZE; i++) {
        integer_array[i] = i * 10;
    }

    // Print values in integer array
    printf("Values in integer array:\n");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", integer_array[i]);
    }
    printf("\n\n");

    // Reallocate memory for integer array with doubled size
    int* new_integer_array = (int*)realloc(integer_array, ARRAY_SIZE * 2 * sizeof(int));

    // Check if memory reallocated successfully
    if(new_integer_array == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    printf("Memory reallocated successfully and integer array size doubled to %d\n\n", ARRAY_SIZE * 2);

    // Update pointer to new integer array
    integer_array = new_integer_array;

    // Initialize new values in integer array
    for(int i = ARRAY_SIZE; i < ARRAY_SIZE * 2; i++) {
        integer_array[i] = i * 10;
    }

    // Print values in integer array
    printf("New values in integer array:\n");
    for(int i = 0; i < ARRAY_SIZE * 2; i++) {
        printf("%d ", integer_array[i]);
    }
    printf("\n\n");

    // Deallocate memory for integer array
    free(integer_array);

    printf("Memory deallocated successfully\n");

    return 0;
}