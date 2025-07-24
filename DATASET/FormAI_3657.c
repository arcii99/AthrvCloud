//FormAI DATASET v1.0 Category: Memory management ; Style: invasive
#include <stdlib.h>
#include <stdio.h>

int main() {

    // Allocate 50 integers worth of memory
    int* ptr = malloc(sizeof(int) * 50);

    printf("Memory allocated at address: %p\n", ptr);

    // Write some values to the allocated memory
    for(int i=0; i<50; i++) {
        *(ptr+i) = i+1;
    }

    // Read and print the values from the allocated memory
    for(int i=0; i<50; i++) {
        printf("%d ", *(ptr+i));
    }
    printf("\n");

    // Create a new pointer and assign it to the same address
    // This will create a memory leak as we lose access to the
    // original pointer and can no longer free the allocated memory
    int* newPtr = ptr;

    printf("Memory allocated at address: %p\n", newPtr);

    // Write some new values to the shared memory
    for(int i=0; i<50; i++) {
        *(newPtr+i) = (i+1) * 2;
    }

    // Read and print the values from the shared memory
    for(int i=0; i<50; i++) {
        printf("%d ", *(newPtr+i));
    }
    printf("\n");

    printf("Program terminating without freeing memory!\n");

    return 0;
}