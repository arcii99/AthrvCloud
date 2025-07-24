//FormAI DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr = (int*) malloc(3 * sizeof(int)); // Allocating memory for 3 integers
    if (ptr == NULL) { // Checking if allocation was successful
        printf("Memory allocation failed!\n");
        return 1; // Terminating the program
    }
    
    // Writing values to the allocated memory
    *(ptr + 0) = 10;
    *(ptr + 1) = 20;
    *(ptr + 2) = 30;
    
    // Printing the values from the allocated memory
    printf("Values in memory location: %d %d %d\n", *(ptr + 0), *(ptr + 1), *(ptr + 2));
    
    // Re-allocating memory for 5 integers
    int* new_ptr = (int*) realloc(ptr, 5 * sizeof(int));
    if (new_ptr == NULL) { // Checking if re-allocation was successful
        printf("Memory re-allocation failed!\n");
        free(ptr); // Freeing the original allocation
        return 1; // Terminating the program
    }
    
    // Writing new values to the newly allocated memory
    *(new_ptr + 3) = 40;
    *(new_ptr + 4) = 50;
    
    // Printing all the values from the newly allocated memory
    printf("Values in memory location: %d %d %d %d %d\n", *(new_ptr + 0), *(new_ptr + 1), *(new_ptr + 2), *(new_ptr + 3), *(new_ptr + 4));
    
    free(new_ptr); // Freeing the memory
    
    return 0; // Terminating the program
}