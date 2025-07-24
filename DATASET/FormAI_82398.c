//FormAI DATASET v1.0 Category: Pattern printing ; Style: beginner-friendly
#include <stdio.h>

int main()
{
    int side, i, j, k, l;

    printf("Enter the side length of the pattern: ");
    scanf("%d", &side);

    for (i = 0; i < side; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    for (k = 0; k < side; k++)
    {
        for (l = side-1; l > k; l--)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}