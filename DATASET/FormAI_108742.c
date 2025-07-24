//FormAI DATASET v1.0 Category: Memory management ; Style: energetic
// Let's create a program that manages memory allocation and deallocation
// This program will be responsible for creating a dynamic array of integers and resizing it accordingly
// As a bonus, we'll also implement a feature to free the allocated memory after it's no longer required

#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

int main()
{
    int array_size = 5; // Initial array size
    int *dynamic_array = malloc(array_size * sizeof(int)); // Allocate memory for the dynamic array
    
    if(dynamic_array == NULL) // Check if memory allocation was successful
    {
        printf("Failed to allocate memory");
        return 1;
    }
    
    printf("Dynamic array created successfully with size %d\n", array_size);
    
    // Add some elements to the array
    for(int i = 0; i < array_size; i++)
    {
        dynamic_array[i] = i + 1;
    }
    
    // Print the array
    printf("Dynamic array elements: ");
    for(int i = 0; i < array_size; i++)
    {
        printf("%d ", dynamic_array[i]);
    }
    printf("\n");
    
    // Let's resize the array
    array_size = 10;
    int *temp_array = realloc(dynamic_array, array_size * sizeof(int)); // Resize the dynamic array
    
    if(temp_array == NULL)
    {
        printf("Failed to resize memory");
        return 1;
    }
    
    dynamic_array = temp_array; // Update the pointer to the new array
    
    // Add some more elements to the array
    for(int i = 5; i < array_size; i++)
    {
        dynamic_array[i] = i + 1;
    }
    
    // Print the resized array
    printf("Resized dynamic array elements: ");
    for(int i = 0; i < array_size; i++)
    {
        printf("%d ", dynamic_array[i]);
    }
    printf("\n");
    
    // Free the allocated memory
    free(dynamic_array);
    printf("Allocated memory freed successfully\n");
    
    return 0;
}