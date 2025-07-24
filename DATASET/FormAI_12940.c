//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocating memory dynamically using malloc()
    ptr = (int*) malloc(n * sizeof(int));

    // Checking if memory has been allocated successfully
    if(ptr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }
    
    // Storing values in the array
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &ptr[i]);
    }

    printf("\nElements in the array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    // Deallocating memory using free()
    free(ptr);
    printf("\nMemory has been deallocated successfully");
    return 0;
}