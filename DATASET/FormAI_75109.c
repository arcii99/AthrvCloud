//FormAI DATASET v1.0 Category: Memory management ; Style: bold
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    // allocate memory for an array
    int *arr = (int*) malloc(SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // populate the array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i * i;
    }

    // print the array
    printf("Array contents:");
    for (int i = 0; i < SIZE; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    // reallocate memory for a larger array
    int *larger_arr = (int*) realloc(arr, (SIZE*2) * sizeof(int));
    if (larger_arr == NULL) {
        printf("Memory reallocation failed!\n");

        // free the original array
        free(arr);
        return 1;
    }

    // update the array pointer
    arr = larger_arr;

    // populate the rest of the array
    for (int i = SIZE; i < SIZE*2; i++) {
        arr[i] = i * i;
    }

    // print the larger array
    printf("Larger Array contents:");
    for (int i = 0; i < (SIZE*2); i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    // free the array
    free(arr);

    return 0;
}