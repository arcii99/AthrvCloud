//FormAI DATASET v1.0 Category: Memory management ; Style: secure
#include<stdio.h>
#include<stdlib.h>

int main()
{
    // Allocate memory for an integer
    int *num_ptr = NULL;
    num_ptr = (int*)malloc(sizeof(int));
    
    // Check if memory allocated successfully or not
    if(num_ptr == NULL)
    {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    
    // Assign value to the integer
    *num_ptr = 10;
    
    // Print the value of the integer
    printf("Value of num_ptr is %d\n", *num_ptr);
    
    // Free the allocated memory
    free(num_ptr);
    
    // Assign null to the pointer
    num_ptr = NULL;
    
    return 0;
}