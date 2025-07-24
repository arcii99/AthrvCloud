//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;
    int i, n;

    printf("Welcome to the Memory Management program!\n");
    printf("Please enter the number of integers you would like to allocate: ");
    scanf("%d", &n);

    // allocate memory dynamically
    ptr = (int*)calloc(n, sizeof(int));

    // check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(1);
    }

    printf("Memory allocation successful! Please enter %d integers:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("The integers you entered are:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    printf("\n");

    // deallocate the allocated memory
    free(ptr);

    printf("Memory deallocation successful! Goodbye!");

    return 0;
}