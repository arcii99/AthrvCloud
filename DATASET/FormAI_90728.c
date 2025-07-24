//FormAI DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr; // Pointer variable to store address of memory block
    int size; // Variable to store the size of memory block
    
    printf("Enter the size of the memory block in bytes: "); // Prompt the user to enter the size of memory block
    scanf("%d", &size); // Read the input size from the user
    
    ptr = (int*) malloc(size); // Dynamically allocate memory block of 'size' bytes and store the address in 'ptr' variable
    
    if (ptr != NULL) // Check if memory block allocation is successful
    {
        printf("Memory block of %d bytes has been allocated successfully.\n", size);
        
        // Write some values to the memory block
        int i;
        for (i = 0; i < size; i++)
        {
            *(ptr+i) = i;
        }
        
        // Read and print the values from the memory block
        printf("The values stored in the memory block are:\n");
        for (i = 0; i < size; i++)
        {
            printf("%d ", *(ptr+i));
        }
        
        free(ptr); // Deallocate the memory block to avoid memory leaks
        printf("\nMemory block has been deallocated successfully.\n");
    }
    else
    {
        printf("Memory block allocation has failed.\n");
    }
    
    return 0;
}