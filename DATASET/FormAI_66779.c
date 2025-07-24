//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr; // Declare an integer pointer variable
    int n = 5; // Declare and initialize an integer variable with value 5
    printf("Welcome to the cheerful memory allocation program!\n");
    printf("We will allocate memory for %d integers!\n", n);
    
    // Allocate memory dynamically using malloc() function
    ptr = (int*) malloc(n * sizeof(int));
    
    // Checking if memory has been successfully allocated
    if (ptr == NULL)
    {
        printf("Error! Memory allocation failed!");
        exit(0);
    }
    
    printf("Memory allocation is successful with malloc() function!\n");
    
    // Initialize the allocated memory
    for (int i=0; i<n; i++)
    {
        ptr[i] = i+1;
    }
    
    printf("Values in the allocated memory:\n");
    for (int i=0; i<n; i++)
    {
        printf("%d ", ptr[i]);
    }
    
    // Deallocate memory using free() function
    free(ptr);
    printf("\nMemory deallocation is successful with free() function!\n");
    printf("Thank you for using our cheerful memory allocation program!\n");
    
    return 0;
}