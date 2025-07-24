//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr; //declare pointer
    int size; //declare size variable

    printf("Enter size of integer array:\n");
    scanf("%d", &size);

    ptr = (int*) malloc(size * sizeof(int)); //allocate memory dynamically

    if(ptr == NULL) //check if allocation was successful
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    else
    {
        printf("Memory allocation successful.\n");

        printf("Enter integer values:\n");
        for(int i=0; i<size; i++)
        {
            scanf("%d", ptr + i); //store user input in allocated memory
        }

        printf("Array values are:\n");
        for(int i=0; i<size; i++)
        {
            printf("%d \n", *(ptr + i)); //display values stored in allocated memory
        }

        free(ptr); //free allocated memory
        printf("Memory has been freed!\n");
    }

    return 0;
}