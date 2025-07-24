//FormAI DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an array of 5 integers
    int *arr = (int*) malloc(5*sizeof(int));

    // Initialize the array
    for (int i = 0; i < 5; i++) {
        arr[i] = i+1;
    }

    // Print the array
    printf("Array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the memory allocated for the array
    free(arr);

    // Allocate memory for a string
    char *str = (char*) malloc(6*sizeof(char));

    // Copy a string into the memory
    strcpy(str, "Hello");

    // Print the string
    printf("String: %s\n", str);

    // Reallocate memory for a larger string
    str = (char*) realloc(str, 12*sizeof(char));

    // Concatenate a string to the existing string
    strcat(str, " World!");

    // Print the concatenated string
    printf("Concatenated string: %s\n", str);

    // Free the memory allocated for the string
    free(str);

    return 0;
}