//FormAI DATASET v1.0 Category: Memory management ; Style: brave
#include<stdio.h>
#include<stdlib.h>

// This program demonstrates dynamic memory allocation and deallocation in C

int main()
{
    int n, *arr, sum=0;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    // Allocating memory dynamically based on user input
    arr = (int*)malloc(n * sizeof(int));

    // Error handling if memory allocation fails
    if(arr==NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }

    // Taking user input for array elements
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", arr+i);
        sum += *(arr+i);
    }

    // Displaying array elements and their sum
    printf("Array elements are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ", *(arr+i));
    }

    printf("\nSum of array elements is: %d", sum);

    // Freeing up the dynamically-allocated memory
    free(arr);

    return 0;
}