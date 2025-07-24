//FormAI DATASET v1.0 Category: Memory management ; Style: content
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr;
    int n, i, sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // allocate memory dynamically
    ptr = (int*) malloc(n * sizeof(int));

    if(ptr == NULL)                     
    {
        printf("Memory allocation failed.");
        exit(0);
    }

    // input array elements
    printf("Enter elements of array:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }

    // display array elements
    printf("Array elements:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", *(ptr+i));
    }

    // deallocate allocated memory
    free(ptr);

    printf("\nSum of array elements is %d", sum);

    return 0;
}