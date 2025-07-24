//FormAI DATASET v1.0 Category: Pattern printing ; Style: detailed
#include <stdio.h>

int main()
{
    int rows, i, j, space, k = 0;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; ++i, k = 0)
    {
        for (space = 1; space <= rows - i; ++space)
        {
            printf(" ");
        }

        while (k != 2 * i - 1)
        {
            printf("*");
            ++k;
        }

        printf("\n");
    }

    k = 1;

    for (i = 1; i <= rows - 1; ++i, k = 0)
    {
        for (space = 1; space <= i; ++space)
        {
            printf(" ");
        }

        while (k != 2 * (rows - i) - 1)
        {
            printf("*");
            ++k;
        }

        printf("\n");
    }

    return 0;
}