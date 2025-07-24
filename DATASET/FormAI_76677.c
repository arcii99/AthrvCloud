//FormAI DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, *newPtr;

    //Allocate memory for 5 integers
    ptr = (int*) malloc(5 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    //Assign values to allocated memory
    for (int i = 0; i < 5; i++) {
        *(ptr + i) = i * 2;
    }

    //Print values of allocated memory
    printf("Values of allocated memory before reallocation: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }

    //Reallocate memory for 10 integers
    newPtr = (int*) realloc(ptr, 10 * sizeof(int));
    if (newPtr == NULL) {
        printf("Memory reallocation failed\n");

        //Free previously allocated memory
        free(ptr);
        exit(1);
    } else {
        ptr = newPtr;
    }

    //Assign values to reallocated memory
    for (int i = 5; i < 10; i++) {
        *(ptr + i) = i * 2;
    }

    //Print values of reallocated memory
    printf("\nValues of reallocated memory after reallocation: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr + i));
    }

    //Free allocated memory
    free(ptr);

    return 0;
}