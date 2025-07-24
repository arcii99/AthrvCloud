//FormAI DATASET v1.0 Category: Memory management ; Style: content
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Allocate memory for an integer pointer
    int* num_ptr = (int*) malloc(sizeof(int));

    // Check for successful allocation
    if (num_ptr == NULL) {
        printf("Memory allocation failed. Exiting program...\n");
        exit(1);
    }

    // Set the value of the integer that the pointer points to
    *num_ptr = 42;

    // Print the value of the integer
    printf("Value of num_ptr: %d\n", *num_ptr);

    // Free the allocated memory
    free(num_ptr);

    // Try to access the value of the integer after freeing
    printf("Value of num_ptr after freeing: %d\n", *num_ptr);

    return 0;
}