//FormAI DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, i, n;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));
    if(ptr == NULL)
    {
        printf("Error: Memory allocation failed.");
        exit(0);
    }

    printf("Enter the integers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("The integers entered are: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    printf("\nMemory has been freed.");

    return 0;
}