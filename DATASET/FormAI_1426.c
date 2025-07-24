//FormAI DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr; // pointer to integer array
    int size; // size of the array

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // allocate memory using calloc
    arr = (int *)calloc(size, sizeof(int));

    // check if memory was allocated
    if(arr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1); // terminate the program
    }

    // let user enter values
    printf("Enter %d numbers:\n", size);
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // display values
    printf("Numbers entered are:\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    // free allocated memory
    free(arr);

    return 0;
}