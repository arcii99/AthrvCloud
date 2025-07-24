//FormAI DATASET v1.0 Category: Pattern printing ; Style: random
#include <stdio.h>

int main()
{
    int i, j, n, k = 0;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
            k++;

        for (j = 1; j <= i; j++)
        {
            if (j % 2 != 0)
                printf("%d", k);
            else
                printf("*");
        }

        printf("\n");
    }

    return 0;
}