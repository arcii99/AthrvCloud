//FormAI DATASET v1.0 Category: Memory management ; Style: genious
#include <stdio.h>

int main() {
    // allocate memory for an array of 10 integers
    int *arr = (int*) malloc(10 * sizeof(int));

    // check if memory allocation was successful
    if(arr == NULL) {
        printf("Error: Memory allocation failed!");
        return 1;
    }

    // assign values to the array
    for(int i=0; i<10; i++) {
        arr[i] = i+1;
    }

    // print the array
    printf("The array contains: ");
    for(int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }

    // reallocate memory for an array of 20 integers
    int *arr2 = (int*) realloc(arr, 20 * sizeof(int));

    // check if reallocation was successful
    if(arr2 == NULL) {
        printf("Error: Memory reallocation failed!");
        free(arr); // free the previously allocated memory
        return 1;
    }

    // assign values to the new array
    for(int i=10; i<20; i++) {
        arr2[i] = i+1;
    }

    // print the new array
    printf("\nThe new array contains: ");
    for(int i=0; i<20; i++) {
        printf("%d ", arr2[i]);
    }

    // free the memory allocated for the new array
    free(arr2);

    return 0;
}