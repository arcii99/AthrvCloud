//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>

int main()
{
    int i, j, n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (j = n - 1; j >= i; j--)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}