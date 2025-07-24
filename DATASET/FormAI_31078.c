//FormAI DATASET v1.0 Category: Pattern printing ; Style: multivariable
#include <stdio.h>
int main()
{
    int n, i, j, x = 1;
    printf("Enter the number of rows:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j == 1 || j == n || i == 1 || i == n)
            {
                printf("* ");
            }
            else if (j == x || j == n - x + 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        if (i >= 2 && i <= n - 1)
        {
            x++;
        }
        printf("\n");
    }
    return 0;
}