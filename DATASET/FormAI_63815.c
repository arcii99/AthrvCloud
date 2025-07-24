//FormAI DATASET v1.0 Category: Pattern printing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, i, j, k;

    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    for (i = size; i >= 0; i--)
    {
        for (j = size; j > i; j--)
        {
            printf(" ");
        }

        for (k = 1; k <= i; k++)
        {
            printf("%c ", 64 + k); // Print alphabet in romantic style
        }

        printf("\n");
    }

    for (i = 1; i < size; i++)
    {
        for (j = size; j > i; j--)
        {
            printf(" ");
        }

        for (k = 1; k <= i + 1; k++)
        {
            printf("%c ", 64 + k);
        }

        printf("\n");
    }

    return 0;
}