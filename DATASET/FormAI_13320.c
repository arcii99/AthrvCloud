//FormAI DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n, i;
    
    // Get the size of array from user
    printf("Enter size of the array: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    ptr = (int*) malloc(n * sizeof(int));
    
    // Check if memory allocation is successful or not
    if (ptr == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    
    // Enter array elements
    printf("Enter %d elements in the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }
    
    // Print array elements
    printf("Entered %d elements are:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    
    // Free the memory allocated
    free(ptr);
    
    return 0;
}