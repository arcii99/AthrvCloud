//FormAI DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p;
    int size;

    printf("Enter the number of integers to be entered: ");
    scanf("%d", &size);

    p = (int*) malloc(size*sizeof(int)); //Allocate memory

    if(p == NULL)
    {
        printf("Memory allocation failed. Program will now exit!\n");
        exit(0);
    }

    printf("Enter the integers: ");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Entered integers are: ");

    for(int i = 0; i < size; i++)
    {
        printf("%d ", p[i]);
    }

    free(p); //Releasing allocated memory

    return 0;
}