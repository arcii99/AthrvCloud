//FormAI DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10 // Define the size of the array

void* mem_alloc(size_t bytes)
{
    void* ptr = malloc(bytes); // Allocate memory using malloc function
    if (!ptr) { // Check if memory allocation was successful
        printf("Failed to allocate memory\n");
        exit(1);
    }
    return ptr;
}

int main()
{
    int* arr = (int*)mem_alloc(sizeof(int) * ARRAY_SIZE); // Allocate memory for an integer array

    for (int i = 0; i < ARRAY_SIZE; i++) { // Initialize the array values
       arr[i] = i;
    }
    
    printf("The array values are:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) { // Output array values
        printf("%d ", arr[i]);
    }
    
    free(arr); // Free memory

    return 0;
}