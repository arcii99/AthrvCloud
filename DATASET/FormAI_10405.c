//FormAI DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array.
#define MAX_NUM_ELEMENTS 10

int main()
{
    // Dynamically allocate memory for an array of integers.
    int *array = (int*) malloc(MAX_NUM_ELEMENTS * sizeof(int));

    if (array == NULL) {
        printf("Failed to allocate memory for the array.\n");
        return 1;
    }

    // Populate the array with random integers.
    for (int i = 0; i < MAX_NUM_ELEMENTS; i++) {
        array[i] = rand() % 100;
    }

    // Print the contents of the array.
    printf("Original Array:\n");
    for (int i = 0; i < MAX_NUM_ELEMENTS; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Sort the array in ascending order using bubble sort.
    for (int i = 0; i < MAX_NUM_ELEMENTS - 1; i++) {
        for (int j = 0; j < MAX_NUM_ELEMENTS - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Print the sorted array.
    printf("Sorted Array:\n");
    for (int i = 0; i < MAX_NUM_ELEMENTS; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory.
    free(array);

    return 0;
}