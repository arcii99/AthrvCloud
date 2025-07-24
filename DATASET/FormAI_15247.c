//FormAI DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to my memory management example program!\n");

    // Allocate memory for a string
    char *str = (char*) malloc(10 * sizeof(char));
    if(str == NULL) {
        printf("Failed to allocate memory\n");
        return -1;
    }
    printf("Memory allocated successfully for string!\n");

    // Write to the allocated memory
    sprintf(str, "Hello!");

    // Allocate memory for an array of integers
    int *arr = (int*) calloc(5, sizeof(int));
    if(arr == NULL) {
        printf("Failed to allocate memory\n");
        free(str);
        return -1;
    }
    printf("Memory allocated successfully for integer array!\n");

    // Populate the array with some values
    for(int i = 0; i < 5; i++) {
        arr[i] = i * 2;
    }

    // Reallocate memory for the string
    char *new_str = realloc(str, 20 * sizeof(char));
    if(new_str == NULL) {
        printf("Failed to reallocate memory\n");
        free(arr);
        return -1;
    }
    printf("Memory reallocated successfully for string!\n");

    // Add more text to the string
    sprintf(new_str, "%s World!", new_str);

    // Free up the memory
    free(arr);
    free(new_str);

    printf("Memory has been freed up!\n");

    return 0;
}