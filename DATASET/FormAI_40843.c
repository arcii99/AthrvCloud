//FormAI DATASET v1.0 Category: Memory management ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* ptr = NULL;
    int n, i;
 
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    // Allocating memory using malloc
    ptr = (int*) malloc(n * sizeof(int));
 
    if(ptr == NULL)                     
    {
        printf("Memory Allocation failed\n");
        exit(0);
    }

    else
    {
        printf("Memory Allocation successful\n");
    }
 
    for(i = 0; i < n; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d", (ptr+i));
    }

    printf("The elements are:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ",*(ptr+i));
    }

    // Freeing up the memory
    free(ptr);
 
    return 0;
}