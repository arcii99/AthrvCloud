//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory dynamically for an array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int*) malloc(n * sizeof(int));
    
    // Check if memory was allocated successfully
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Populate array with random numbers
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Resize array to double the size
    printf("Resizing array...\n");
    int *temp = (int*) realloc(arr, 2*n * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(arr);
        return 1;
    }
    arr = temp;
    
    // Add more random numbers to the resized array
    printf("Resized array: ");
    for (int i = n; i < 2*n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free the allocated memory
    free(arr);
    printf("Memory freed successfully!\n");
    
    return 0;
}