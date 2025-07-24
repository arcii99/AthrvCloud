//FormAI DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_elements;
    int *arr;
    
    /* Prompt user for number of elements */
    printf("Enter the number of elements in array: ");
    scanf("%d", &num_elements);
    
    /* Allocate memory dynamically */
    arr = (int*) malloc(num_elements * sizeof(int));
    
    /* Check if allocation was successful */
    if (arr == NULL)
    {
        printf("Memory could not be allocated.");
        exit(0);
    }
    
    /* Populate the array with user input */
    for (int i = 0; i < num_elements; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    /* Display array contents */
    printf("\nArray contents:\n");
    for (int i = 0; i < num_elements; i++)
    {
        printf("%d ", arr[i]);
    }
    
    /* Free allocated memory */
    free(arr);
    
    return 0;
}