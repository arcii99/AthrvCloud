//FormAI DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *ptr;
    int n = 5;

    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));

    // Check if the memory is allocated successfully
    if (ptr == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    
    // Initialize the array
    for (int i=0; i<n; i++) {
        *(ptr+i) = i * 2;
    }

    // Print the elements of the array
    printf("Array elements are: ");
    for (int i=0; i<n; i++) {
        printf("%d ", ptr[i]);
    }

    // Reallocate memory using realloc()
    int new_n = 8;
    ptr = (int*)realloc(ptr, new_n * sizeof(int));

    // Check if the memory is allocated successfully
    if (ptr == NULL) {
        printf("Memory reallocation failed. Exiting.\n");
        exit(1);
    }

    // Fill the newly allocated memory with values
    for (int i=n; i<new_n; i++) {
        *(ptr+i) = i * 3;
    }

    // Print the elements of the array
    printf("\nArray elements after reallocation are: ");
    for (int i=0; i<new_n; i++) {
        printf("%d ", ptr[i]);
    }

    // Free the allocated memory
    free(ptr);

    return 0;
}