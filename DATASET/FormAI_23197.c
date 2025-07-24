//FormAI DATASET v1.0 Category: Pattern printing ; Style: portable
#include <stdio.h>

int main()
{
    int i, j, k;

    // Loop for top half of pattern
    for (i = 1; i <= 5; i++)
    {
        // Loop for printing numbers
        for (j = i; j <= 5; j++)
            printf("%d ", j);
        
        // Loop for printing stars
        for (k = 1; k <= 2 * i - 1; k++)
            printf("*");
        
        // Loop for printing numbers again in reverse order
        for (j = 5; j >= i; j--)
            if (j != 5) // to prevent double printing of last number
                printf(" %d", j);
            
        printf("\n"); // move to next line
    }

    // Loop for bottom half of pattern
    for (i = 4; i >= 1; i--)
    {
        for (j = i; j <= 5; j++)
            printf("%d ", j);
        
        for (k = 1; k <= 2 * i - 1; k++)
            printf("*");
        
        for (j = 5; j >= i; j--)
            if (j != 5)
                printf(" %d", j);
        
        printf("\n"); // move to next line
    }

    return 0; // successful termination of program
}