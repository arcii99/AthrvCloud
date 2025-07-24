//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    // get user input for size of array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // dynamically allocate memory for array
    int *arr = (int*) malloc(size * sizeof(int));

    // check if memory was allocated successfully
    if (arr == NULL) {
        printf("Oops! Memory allocation failed.\n");
        return 1;
    }

    // assign values to array
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    // print array values
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // free dynamically allocated memory
    free(arr);

    return 0;
}