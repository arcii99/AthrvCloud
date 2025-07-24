//FormAI DATASET v1.0 Category: Pattern printing ; Style: Alan Touring
#include <stdio.h>

// C Pattern Printing Program
// Print a diamond shape using asterisks

int main()
{
    int i, j, k, space = 1;
    
    for (i = 1; i <= 5; i++)
    {
        for (k = space; k <= 5; k++)
        {
            printf(" ");
        }
        space++;
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    space = 4;
    for (i = 1; i <= 4; i++)
    {
        for (k = 1; k <= space; k++)
        {
            printf(" ");
        }
        space--;
        for (j = 1; j <= 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}