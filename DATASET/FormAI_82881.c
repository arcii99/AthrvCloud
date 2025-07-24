//FormAI DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Allocate memory for an array of 10 integers
    int* myArray = (int*)malloc(10 * sizeof(int));

    // Fill the array with even numbers
    int i;
    for (i = 0; i < 10; i++) {
        myArray[i] = 2 * i;
    }

    // Print out the array
    printf("My array contains the following elements:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n\n");

    // Reallocate memory for a larger array of 15 integers
    myArray = (int*)realloc(myArray, 15 * sizeof(int));

    // Fill the new part of the array with odd numbers
    for (i = 10; i < 15; i++) {
        myArray[i] = 2 * i + 1;
    }

    // Print out the updated array
    printf("My array now contains the following elements:\n");
    for (i = 0; i < 15; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n\n");

    // Free the memory allocated for the array
    free(myArray);

    return 0;
}