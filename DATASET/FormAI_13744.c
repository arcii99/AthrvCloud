//FormAI DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pointer;
    int size, i, sum = 0;

    // Get the size of the array from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array using malloc
    pointer = (int*) malloc(size * sizeof(int));

    // Check if memory is allocated successfully
    if(pointer == NULL) {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    // Get array elements from the user
    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++) {
        scanf("%d", pointer + i);
    }

    // Calculate the sum of array elements
    for(i = 0; i < size; i++) {
        sum += *(pointer + i);
    }

    // Print the sum of array elements
    printf("Sum of array elements: %d\n", sum);

    // Free the dynamically allocated memory
    free(pointer);

    return 0;
}