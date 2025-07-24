//FormAI DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory dynamically
void allocateMemory(int n)
{
    int *ptr = (int*)malloc(n*sizeof(int));
    
    if (ptr == NULL)  // Check for allocation failure
    {
        printf("\nError! Unable to allocate memory.");
        exit(0);
    }
    
    // Store values in dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        *(ptr + i) = i + 1;
    }
    
    // Display values stored in memory
    printf("\nValues stored in dynamically allocated memory: ");
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }
    
    free(ptr);  // Free dynamically allocated memory
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Call function to allocate memory
    allocateMemory(n);
    
    return 0;
}