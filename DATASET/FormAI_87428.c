//FormAI DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr = NULL;
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    // Allocate memory dynamically
    arr = (int*)malloc(size * sizeof(int));
    
    // Check if memory allocation was successful
    if(arr == NULL)
    {
        printf("Memory allocation failed.");
        return 0;
    }
    
    printf("Enter %d elements of the array: ", size);
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("The elements of the array are: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
    // Free the dynamically allocated memory
    free(arr);
    
    return 0;
}