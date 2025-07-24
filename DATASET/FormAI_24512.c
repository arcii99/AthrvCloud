//FormAI DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* x = malloc(sizeof(int)); // Allocating memory for an integer using malloc
    if (x == NULL) { // Checking if memory allocation failed
        printf("Memory allocation failed!");
        return 1; // Exiting the program with error code 1
    }

    *x = 10; // Assigning a value to the memory location

    printf("The value at x is: %d\n", *x);

    free(x); // De-allocating the memory

    return 0;
}