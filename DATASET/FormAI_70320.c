//FormAI DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    //allocate memory dynamically
    arr = (int*) malloc(n*sizeof(int));

    //check if memory allocation was successful
    if(arr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter %d elements:\n", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The elements of the array are:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    //free the memory allocated
    free(arr);

    return 0;
}