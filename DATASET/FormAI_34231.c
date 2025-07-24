//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

int main()
{
    int n = 5;

    // Upper half of the pattern
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    // Lower half of the pattern
    for(int i=n-1; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}