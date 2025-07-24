//FormAI DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = NULL; // Pointer to array of integers
    int size = 10; // Initial size of the array
    int index = 0; // Index of the array
    int number; // User input number

    // Dynamically allocate memory for the array
    array = (int*) malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Prompt the user to enter numbers until they input 0
    do {
        printf("Enter a number (0 to stop): ");
        scanf("%d", &number);

        // Reallocate memory if needed
        if (index == size) {
            size += 10; // Increase the size of the array by 10 elements
            array = (int*) realloc(array, size * sizeof(int)); // Reallocate memory
            if (array == NULL) {
                printf("Error: Memory reallocation failed.\n");
                exit(1);
            }
        }

        array[index] = number; // Add the number to the array
        index++; // Increment the index
    } while (number != 0);

    printf("You entered %d numbers.\n", index - 1); // Subtract 1 to exclude the final 0

    // Print the numbers in the array
    printf("Numbers in the array:\n");
    for (int i = 0; i < index - 1; i++) {
        printf("%d\n", array[i]);
    }

    free(array); // Release the memory allocated by malloc/realloc

    return 0;
}