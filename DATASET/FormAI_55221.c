//FormAI DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define ALLOC_SIZE 10
#define MAX_ALLOCS 100

int main() {
    void* ptr[MAX_ALLOCS];
    int count = 0;

    printf("Memory Management Example Program\n\n");

    // Allocate memory
    while(count < MAX_ALLOCS) {
        ptr[count] = malloc(sizeof(int) * ALLOC_SIZE);
        if(ptr[count] == NULL) {
            printf("Memory allocation error!\n");
            break;
        }
        count++;
    }

    // Print allocated memory addresses
    printf("Allocated memory addresses:\n");
    for(int i = 0; i < count; i++) {
        printf("%p\n", ptr[i]);
    }

    // Free allocated memory in reverse order
    printf("\nFreeing allocated memory in reverse order...\n");
    for(int i = count-1; i >= 0; i--) {
        free(ptr[i]);
    }

    printf("\nMemory deallocated successfully!\n");

    return 0;
}