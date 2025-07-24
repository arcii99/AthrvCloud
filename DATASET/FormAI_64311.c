//FormAI DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

/* This program demonstrates the management of memory in C programming language.
 * It allocates 100 integers in memory and then tests it by adding all these integers
 * and printing the sum on the screen.
 */

int main() {

    int *ptr = NULL;
    int sum = 0;

    // Allocate memory
    ptr = (int*) malloc(100 * sizeof(int));

    // Check if memory has been allocated successfully
    if (ptr == NULL) {
        printf("Memory allocation failed! Exiting...");
        exit(1);
    }

    // Set the values of the allocated memory
    for (int i = 0; i < 100; i++) {
        ptr[i] = i;
    }

    // Calculate the sum of the integers in the allocated memory
    for (int i = 0; i < 100; i++) {
        sum += ptr[i];
    }

    // Free the allocated memory
    free(ptr);

    // Print the sum of the integers
    printf("The sum of the integers is %d", sum);

    return 0;
}