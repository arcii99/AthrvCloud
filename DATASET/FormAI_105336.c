//FormAI DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size, i, sum = 0;

    // Prompt user for input
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory dynamically
    arr = (int*) malloc(size * sizeof(int));

    // Check if allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }

    // Prompt user to enter elements
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Print the sum
    printf("The sum of the elements is: %d\n", sum);

    // Free the allocated memory
    free(arr);

    return 0;
}