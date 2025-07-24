//FormAI DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOCATIONS 1000 // Define the maximum number of allocations we can make

int main(void)
{
    int *pointers[MAX_ALLOCATIONS]; // Define an array of pointers for our allocations
    int numAllocations = 0; // Initialize the number of allocations we've made to 0
    
    // Loop through and allocate memory until we reach the maximum number of allocations or we run out of memory
    while (numAllocations < MAX_ALLOCATIONS)
    {
        int *ptr = malloc(sizeof(int)); // Allocate memory for an int
        if (ptr == NULL)
        {
            printf("Could not allocate more memory.\n");
            break;
        }
        else
        {
            *ptr = numAllocations; // Set the value of the int to our current allocation number
            pointers[numAllocations++] = ptr; // Add the pointer to our array and increment the number of allocations
        }
    }
    
    // Loop through our allocations and print out their values
    for (int i = 0; i < numAllocations; i++)
    {
        printf("Allocation %d: %d\n", i, *pointers[i]);
        free(pointers[i]); // Free the memory we allocated
    }
    
    return 0;
}