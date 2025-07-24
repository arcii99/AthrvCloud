//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer with malloc()
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }
    
    // Store 42 in the allocated memory
    *ptr = 42;
    printf("The value of the integer at %p is %d.\n", ptr, *ptr);
    
    // Reallocate memory for a larger integer with realloc()
    int *new_ptr = (int *)realloc(ptr, sizeof(int) * 2);
    if (new_ptr == NULL) {
        printf("Memory allocation error.\n");
        free(ptr);
        return 1;
    }
    
    // Store 100 in the first integer's memory
    *new_ptr = 100;
    printf("The value of the first integer at %p is now %d.\n", new_ptr, *new_ptr);
    
    // Store 200 in the second integer's memory
    *(new_ptr + 1) = 200;
    printf("The value of the second integer at %p is now %d.\n", new_ptr + 1, *(new_ptr + 1));
    
    // Deallocate memory with free()
    free(new_ptr);
    
    return 0;
}