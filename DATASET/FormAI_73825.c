//FormAI DATASET v1.0 Category: Memory management ; Style: genious
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    int n, i, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    // Dynamically allocating memory
    ptr = (int*)malloc(n * sizeof(int));

    // Checking if memory has been allocated or not
    if(ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
        printf("Memory has been successfully allocated using malloc.\n");

    //Getting input
    for(i=0; i<n; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",ptr+i);
        sum += *(ptr+i);
    }

    //Displaying output
    printf("The elements entered are: ");
    for(i=0; i<n; i++)
        printf("%d ",*(ptr+i));
    printf("\nThe sum of the elements is: %d",sum);

    //Freeing up the memory
    free(ptr);
    printf("\nMemory has been successfully freed using free() function.");

    return 0;
}