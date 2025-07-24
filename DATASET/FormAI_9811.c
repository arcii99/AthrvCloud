//FormAI DATASET v1.0 Category: Memory management ; Style: rigorous
//Program to demonstrate Dynamic Memory Allocation in C

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;   //Declare pointer variable
    int n, sum = 0;     //Declare integer entities for length and sum

    //Taking length of the array from user
    printf("Enter number of elements:");
    scanf("%d", &n);

    //Memory allocation for n number of integers
    ptr = (int*) malloc(n * sizeof(int));

    //Check if memory allocation is successful or not
    if(ptr == NULL)                     
    {                                  
        printf("Memory allocation failed");
        exit(0);                      
    }                            

    //Taking Array input from user
    printf("Enter elements of array:");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);      //Taking input directly using pointer arithmetic
        sum += *(ptr + i);     //finding sum of the array
    }

    //Displaying array elements with their addresses
    printf("\nArray elements with their addresses\n");
    for(int i = 0; i < n; i++)
    {
        printf("Element %d: %d\tAddress: %p\n", i+1, *(ptr + i), (ptr + i));   //Printing value and address using pointer arithmetic
    }

    //Displaying the sum of array elements
    printf("\nThe sum of array elements is %d\n",sum);

    free(ptr); //De-allocating memory

    return 0; //Program ends
}