//FormAI DATASET v1.0 Category: Memory management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Please enter the size of the array: ");
    scanf("%d", &n);

    int *arr;
    arr = (int*) malloc(n * sizeof(int)); // allocate memory for the array

    if (arr == NULL) // if memory allocation fails
    {
        printf("Memory allocation failed!");
        exit(1); // exit the program
    }

    for (int i = 0; i < n; i++) // initialize array values
    {
        arr[i] = i + 1;
    }

    printf("The values in the array are: ");
    for (int i = 0; i < n; i++) // print array values
    {
        printf("%d ", arr[i]);
    }

    free(arr); // deallocate memory

    return 0;
}