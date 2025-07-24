//FormAI DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of integers to be stored: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    int *arr = (int*) malloc(n * sizeof(int));

    // Check if memory is successfully allocated
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }

    // Read in the elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print out the elements
    printf("The elements of the array are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}