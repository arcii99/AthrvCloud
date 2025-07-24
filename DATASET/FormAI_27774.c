//FormAI DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Let's allocate some memory dynamically
    printf("Initializing memory allocation...\n");
    int *ptr = (int*) malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!");
        return 0;
    }
    printf("Memory allocation successful.\n");

    // Let's write some data to the memory block
    printf("Writing data to memory block...\n");
    *ptr = 27;
    printf("Data written successfully.\n");

    // Let's read the data from the memory block
    printf("Reading data from memory block...\n");
    printf("Value of the data: %d\n", *ptr);

    // Let's free the memory
    printf("Freeing up the memory block...\n");
    free(ptr);
    printf("Memory freed successfully.\n");

    return 0;
}