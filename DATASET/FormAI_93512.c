//FormAI DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10, y = 0;
    int *ptr;

    // Allocate memory for a pointer
    ptr = (int*) malloc(sizeof(int));

    // Check if allocation was successful
    if (ptr == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter a value for y: ");
    scanf("%d", &y);

    // Check if y is zero
    if (y == 0) {
        printf("Error: Division by zero attempted.\n");
        free(ptr);
        exit(1);
    }

    *ptr = x / y;

    printf("Result: %d\n", *ptr);

    // Free memory
    free(ptr);

    return 0;
}