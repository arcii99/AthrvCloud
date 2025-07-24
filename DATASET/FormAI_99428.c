//FormAI DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main() {
    int* ptr = (int*) malloc(SIZE * sizeof(int)); // allocating memory
    
    if (ptr == NULL) { // checking if memory allocation was successful
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    // Randomly assigning values to the memory block
    for (int i = 0; i < SIZE; i++) {
        *(ptr + i) = rand() % 100;
    }
    
    // Printing the values before freeing memory
    printf("Values before freeing memory:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    
    // Freeing the allocated memory
    free(ptr);
    
    // Printing the values after freeing memory
    printf("Values after freeing memory:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    
    return 0;
}