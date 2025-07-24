//FormAI DATASET v1.0 Category: Memory management ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 5

int main()
{
    int *ptr;
    
    // allocating memory using malloc()
    ptr = (int*) malloc(SIZE * sizeof(int));
    
    if(ptr == NULL)
    {
        printf("\nMemory allocation failed.\n");
        exit(0);
    }
    else
    {
        printf("\nMemory allocation successful. Let's put some data in the allocated memory...\n");
    }

    // putting some data in the allocated memory
    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;
    ptr[3] = 40;
    ptr[4] = 50;

    // displaying the data from the allocated memory
    printf("\nThe data stored in the memory is:\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", ptr[i]);
    }

    // deallocating the memory using free()
    free(ptr);
    printf("\nMemory deallocated successfully. But wait, there's more...!\n");

    ptr = (int*) calloc(SIZE, sizeof(int));

    if(ptr == NULL)
    {
        printf("\nMemory allocation failed.\n");
        exit(0);
    }
    else
    {
        printf("\nMemory allocation successful. Let's put some new data in the newly allocated memory...\n");
    }

    // putting some new data in the newly allocated memory
    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;
    ptr[3] = 400;
    ptr[4] = 500;

    // displaying the new data from the allocated memory
    printf("\nThe new data stored in the memory is:\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", ptr[i]);
    }

    // deallocating the memory using free()
    free(ptr);
    printf("\nMemory deallocated successfully again. Aren't you surprised?\n");

    return 0;
}