//FormAI DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr;
    int n, i, sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int)); // allocating memory dynamically

    if (ptr == NULL) // checking if memory is allocated successfully
    {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    printf("Enter the elements of the array: ");

    for (i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d", sum);

    // freeing the allocated memory 
    free(ptr);
   
    return 0;
}