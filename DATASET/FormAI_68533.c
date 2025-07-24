//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum = 0, *ptr, i;

    printf("Enter the number of integers you want to allocate memory for: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int)); // Dynamically allocate memory using malloc

    if(ptr == NULL)                     
    {
        printf("Memory cannot be allocated.");
        exit(0);
    }

    printf("Enter %d integers: ", n);
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", ptr+i);              // Accept values from the user

        sum += *(ptr+i);                 // Summing up the entered integers
    }

    printf("The entered integers are: ");
    
    for(i = 0; i < n; i++) 
    {
        printf("%d, ", *(ptr+i));        // Displaying the entered integers
    }

    printf("\nThe sum of the entered integers is: %d", sum);

    free(ptr);                           // Freeing the allocated memory
    ptr = NULL;

    return 0;
}