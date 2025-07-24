//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
#include <stdio.h>

int main()
{
    int i, j, k;

    printf("\n\nLet's make a Smiley Face using C Pattern Printing!\n\n");

    for (i = 1; i <= 15; i++)
    {
        for (j = 1; j <= 16 - i; j++)
        {
            printf(" ");
        }
        for (k = 1; k <= i + i; k++)
        {
            if (i > 10 && k == 1)
            {
                printf(" ");
            }
            else if (k == 1 || k == i + i)
            {
                printf("*");
            }
            else if (i > 5 && i < 10 && k >= i && k <= i + i - 1)
            {
                printf(":)");
            }
            else if (i > 9 && i < 14 && k >= i && k <= i + i - 1)
            {
                printf(";;)");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n\nHooray! We made a Smiley Face using C Pattern Printing!\n\n");

    return 0;
}