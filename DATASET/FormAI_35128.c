//FormAI DATASET v1.0 Category: Pattern printing ; Style: light-weight
#include <stdio.h>

int main()
{
    int n, i, j, k;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Top half of the pattern
    for(i = n; i > 0; i--)
    {
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }
        for(k = n; k > i; k--)
        {
            printf(" ");
        }
        printf("\n");
    }

    // Bottom half of the pattern
    for(i = 0; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }
        for(k = n; k > i; k--)
        {
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}