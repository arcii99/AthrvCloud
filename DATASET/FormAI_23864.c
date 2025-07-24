//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //allocating memory blocks of size 4 bytes
    int *ptr = (int*)malloc(5*sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    //filling memory with values
    for(int i=0;i<5;i++)
    {
        *(ptr+i) = i+1;
    }

    //printing the memory block
    printf("The memory block contains:\n");
    for(int i=0;i<5;i++)
    {
        printf("%d ", *(ptr+i));
    }

    //reallocating memory block to a larger size
    ptr = (int*)realloc(ptr, 10*sizeof(int));
    if(ptr == NULL)
    {
        printf("Memory reallocation failed!");
        return 1;
    }

    //filling new memory with values
    for(int i=5;i<10;i++)
    {
        *(ptr+i) = i+1;
    }

    //printing the updated memory block
    printf("\n\nThe updated memory block contains:\n");
    for(int i=0;i<10;i++)
    {
        printf("%d ", *(ptr+i));
    }

    //freeing the allocated memory
    free(ptr);

    return 0;
}