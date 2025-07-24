//FormAI DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // allocate memory for an integer array of size 5
    int *arr = (int*)malloc(sizeof(int) * 5);

    // check if malloc was successful
    if (arr == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    // fill the array with some values
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i * 2;
    }

    // print the values of the array
    printf("The values of the array are: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // change the size of the array to 10
    int *temp = (int*)realloc(arr, sizeof(int) * 10);

    // check if realloc was successful
    if (temp == NULL)
    {
        printf("Memory reallocation failed!");
        return 1;
    }
    else
    {
        arr = temp;
    }

    // fill the array with some more values
    for (int i = 5; i < 10; i++)
    {
        arr[i] = i * 2;
    }

    // print the values of the resized array
    printf("The values of the resized array are: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // free the memory allocated for the array
    free(arr);

    return 0;
}