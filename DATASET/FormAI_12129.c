//FormAI DATASET v1.0 Category: Memory management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements you want to store: ");
    scanf("%d", &n);

    // Dynamically allocating memory for array
    int *arr = (int*) malloc(n * sizeof(int));

    // Checking if memory allocation was successful or not
    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Taking user input for array elements
    printf("Enter %d elements to store in the array: \n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Displaying the array elements
    printf("\nArray elements are: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Freeing the allocated memory
    free(arr);
    printf("\nMemory freed successfully!");

    return 0;
}