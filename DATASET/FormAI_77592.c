//FormAI DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, *temp; // declaring two pointer variables
    int n, i, j; // declaring integer variables for size and loops
    printf("Enter the size of the array: ");
    scanf("%d", &n); // taking the input from user for size

    ptr = (int*)malloc(n * sizeof(int)); // allocating memory dynamically using malloc
    temp = ptr; 

    if(ptr == NULL) // checking if the memory is allocated or not
    { 
        printf("Memory cannot be allocated");
        exit(0); // exiting if it's not allocated
    }

    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", ptr); // taking the input from user 
        ptr++;
    }

    ptr = temp;

    printf("The elements of the array are: ");
    for(j=0;j<n;j++)
    {
        printf("%d ", *ptr); // printing the elements that were inputted
        ptr++;
    }

    free(ptr); // deallocating the memory

    return 0;
}