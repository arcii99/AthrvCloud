//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    int* array;

    printf("Enter size of array: ");
    scanf("%d", &size);

    // Memory is allocated dynamically
    array = (int*) malloc(size * sizeof(int));

    // Check if memory allocation was successful or not
    if (array == NULL) {
        printf("Memory allocation failed. Exiting program...\n");
        exit(1);
    }

    // Assign values to array elements
    for (i = 0; i < size; i++) {
        array[i] = i+1;
    }

    // Display array elements
    printf("Array elements are: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // Deallocate memory allocated dynamically
    free(array);

    return 0;
}