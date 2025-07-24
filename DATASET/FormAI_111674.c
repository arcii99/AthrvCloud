//FormAI DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>
int main()
{
    int n, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Upper part of the pattern
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            printf("%d ", j);
        }

        for (k = 1; k < i; k++)
        {
            printf("%d ", i-1);
        }
        printf("\n");
    }

    // Lower part of the pattern
    for (i = n-1; i >= 1; i--)
    {
        for (j = i; j <= n; j++)
        {
            printf("%d ", j);
        }

        for (k = 1; k < i; k++)
        {
            printf("%d ", i-1);
        }
        printf("\n");
    }

    return 0;
}