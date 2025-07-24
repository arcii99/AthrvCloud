//FormAI DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
// Ada Lovelace Style Memory Management Example Program
// Author: Ada Lovelace

#include <stdio.h>
#include <stdlib.h>

void allocate_memory(int **ptr, int size)
{
    *ptr = (int *) malloc(size * sizeof(int));
}

void fill_memory(int *ptr, int size)
{
    for(int i=0; i<size; i++)
    {
        *(ptr+i) = i+1;
    }
}

void display_memory(int *ptr, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ", *(ptr+i));
    }
    printf("\n");
}

int main()
{
    int size = 5;
    int *ptr = NULL;

    allocate_memory(&ptr, size);
    if(ptr == NULL)
    {
        printf("Error: Memory Allocation Failed!\n");
        exit(1);
    }

    printf("Memory Allocated Successfully!\n");
    fill_memory(ptr, size);
    printf("Memory Filled Successfully!\n");
    display_memory(ptr, size);
    printf("Memory Displayed Successfully!\n");

    free(ptr);
    ptr = NULL;
    printf("Memory Freed Successfully!\n");
    return 0;
}