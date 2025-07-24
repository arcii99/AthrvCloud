//FormAI DATASET v1.0 Category: Pattern printing ; Style: thoughtful
#include <stdio.h>

int main()
{
    int row, column;

    //Printing the first pattern
    for(row = 1; row <= 5; row++)
    {
        for(column = 1; column <= row; column++)
        {
            printf("%d", column);
        }
        printf("\n");
    }

    //Adding space between the patterns
    printf("\n");

    //Printing the second pattern
    for(row = 5; row >= 1; row--)
    {
        for(column = row; column >= 1; column--)
        {
            printf("%d", column);
        }
        printf("\n");
    }

    //Adding space between the patterns
    printf("\n");

    //Printing the third pattern
    for(row = 1; row <= 5; row++)
    {
        int i;
        for(i = 1; i <= 5 - row; i++)
        {
            printf(" ");
        }
        for(column = 1; column <= (2 * row) - 1; column++)
        {
            printf("%d", column);
        }
        printf("\n");
    }

    //Adding space between the patterns
    printf("\n");

    //Printing the fourth pattern
    for(row = 1; row <= 5; row++)
    {
        int i;
        for(i = 1; i <= row - 1; i++)
        {
            printf(" ");
        }
        for(column = 1; column <= (2 * (5 - row + 1)) - 1; column++)
        {
            printf("%d", column);
        }
        printf("\n");
    }

    return 0;
}