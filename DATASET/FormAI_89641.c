//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *ptr;
    int size, i, sum=0;
    float avg;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    ptr = (int*) malloc(size*sizeof(int));  // allocating memory

    if(ptr == NULL)  // error if memory is not allocated
    {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    printf("Enter the elements:\n");

    for(i=0; i<size; i++)
    {
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }

    avg = (float)sum / size;
    printf("Average: %.2f\n", avg);

    free(ptr); // freeing the allocated memory
}