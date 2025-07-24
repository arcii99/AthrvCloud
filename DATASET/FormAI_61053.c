//FormAI DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>

int main()
{
    int i, j, k;

    // Printing the first five lines of the pattern
    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }
        for(k = 5 - i; k > 0; k--)
        {
            printf("  ");
        }
        for(k = 5 - i; k > 0; k--)
        {
            printf("  ");
        }
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Printing the next five lines of the pattern
    for(i = 5; i >= 1; i--)
    {
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }
        for(k = 5 - i; k > 0; k--)
        {
            printf("  ");
        }
        for(k = 5 - i; k > 0; k--)
        {
            printf("  ");
        }
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}