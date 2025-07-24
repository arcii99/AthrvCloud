//FormAI DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Initializing a null pointer
    int *ptr = NULL;

    // Attempting to allocate memory to the pointer
    ptr = (int*)malloc(sizeof(int));

    // Checking if allocation was successful
    if (ptr == NULL) {
        // Displaying a custom error message
        fprintf(stderr, "Error - Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    // Storing value in the allocated memory
    *ptr = 10;

    // Display the value 
    printf("The value stored at the memory address is: %d\n", *ptr);

    // Free allocated memory
    free(ptr);

    // Setting pointer to null after freeing the memory
    ptr = NULL;

    // Attempting to free memory again
    free(ptr);

    // Checking if the pointer was set to NULL after freeing memory
    if (ptr != NULL) {
        // Displaying a custom error message
        fprintf(stderr, "Error - Pointer not set to NULL after freeing memory\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}