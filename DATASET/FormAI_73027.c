//FormAI DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    // Upper half of the pattern
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf("*");
        }
        for (k = i; k < n; k++)
        {
            printf("%d", k);
        }
        printf("\n");
    }

    // Lower half of the pattern
    for (i = n-1; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            printf("*");
        }
        for (k = i; k < n; k++)
        {
            printf("%d", k);
        }
        printf("\n");
    }

    return 0;
}