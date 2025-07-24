//FormAI DATASET v1.0 Category: Memory management ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr, *ptr1, n, i, sum = 0;
    
    printf("Enter the number of integers you want to enter: ");
    scanf("%d",&n);

    ptr = (int*) malloc(n * sizeof(int)); // Allocating memory using malloc()
    ptr1 = (int*) calloc(n, sizeof(int)); // Allocating memory using calloc()
    
    // Reading and printing the values using malloc()
    printf("Using malloc():\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the value of integer %d: ",i+1);
        scanf("%d",&ptr[i]);
        printf("The value of integer %d is %d\n",i+1,ptr[i]);
    }
    
    // Reading and printing the values using calloc()
    printf("Using calloc():\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the value of integer %d: ",i+1);
        scanf("%d",&ptr1[i]);
        printf("The value of integer %d is %d\n",i+1,ptr1[i]);
    }
    
    // Freeing the memory allocated using malloc()
    free(ptr);
    
    // Freeing the memory allocated using calloc()
    free(ptr1);
    
    return 0;
}