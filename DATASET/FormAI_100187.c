//FormAI DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* myArray = NULL;
    int size, sum = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    myArray = (int*)malloc(size * sizeof(int));

    // Check if memory is allocated successfully
    if (myArray == NULL) {
        printf("Memory allocation failed.");
        return 0;
    }

    // Read values from user
    for (int i = 0; i < size; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &myArray[i]);
        sum += myArray[i];
    }

    // Print values of the array
    printf("\nValues of the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }

    printf("\nSum of the array elements is: %d", sum);

    // Free the allocated memory
    free(myArray);

    return 0;
}