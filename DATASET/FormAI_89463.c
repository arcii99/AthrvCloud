//FormAI DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>

/* Artistic Searching Algorithm */

int main()
{
    // Declare variables
    int num_elements, i, search_element, found = 0;
    
    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num_elements);

    // Declare the array
    int array[num_elements];

    // Get the elements of the array
    printf("\nEnter %d elements:\n", num_elements);
    for(i=0; i<num_elements; i++)
    {
        scanf("%d", &array[i]);
    }

    // Get the element to be searched
    printf("\nEnter the element to be searched: ");
    scanf("%d", &search_element);

    // Search for the element
    for(i=0; i<num_elements; i++)
    {
        if(array[i] == search_element)
        {
            found = 1;
            break;
        }
    }

    // Print the result
    if(found == 1)
    {
        printf("\nElement found at index %d!\n", i);
    }
    else
    {
        printf("\nElement not found in the array!\n");
    }

    return 0;
}