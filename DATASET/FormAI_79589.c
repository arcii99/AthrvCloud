//FormAI DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{
    // Dynamically allocate memory for an array of integers
    int* array = (int*) malloc(sizeof(int) * 10);

    // Check if the memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation error!");
        exit(1);
    }

    // Populate the array
    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    // Print the original array
    printf("Original Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Reallocate the memory to double the size of the array
    int* new_array = (int*) realloc(array, sizeof(int) * 20);

    // Check if the reallocation was successful
    if (new_array == NULL) {
        printf("Memory reallocation error!");
        exit(1);
    }

    // Update the array pointer to the new location
    array = new_array;

    // Populate the remaining half of the array
    for (int i = 10; i < 20; i++) {
        array[i] = i;
    }

    // Print the updated array
    printf("Updated Array: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(array);

    return 0;
}