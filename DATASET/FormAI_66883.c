//FormAI DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int i, n;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory allocation failed.");
        exit(0);
    }

    printf("Enter the %d integers: ", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    printf("The entered integers are: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    free(ptr);
    printf("\nMemory dynamically allocated has been freed!");

    return 0;
}