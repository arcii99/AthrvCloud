//FormAI DATASET v1.0 Category: Memory management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr = NULL; // Initializing the pointer to NULL

    // Allocating memory dynamically using malloc
    ptr = (int*) malloc(5 * sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Filling the allocated memory with some random values
    for (int i = 0; i < 5; i++) {
        *(ptr + i) = i + 1;
    }

    // Printing the values stored in the memory
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // Reallocating memory dynamically using realloc
    ptr = (int*) realloc(ptr, 10 * sizeof(int));

    if (ptr == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    // Filling the reallocated memory with some more random values
    for (int i = 5; i < 10; i++) {
        *(ptr + i) = i + 1;
    }

    // Printing the values stored in the reallocated memory
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // Deallocating the memory using free
    free(ptr);

    return 0;
}