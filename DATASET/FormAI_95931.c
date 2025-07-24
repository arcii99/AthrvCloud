//FormAI DATASET v1.0 Category: Pattern printing ; Style: immersive
#include <stdio.h>
int main()
{
    int rows, i, j, space = 1;
    printf("\n\n\t\t\tWelcome to the C Pattern Printing Program!\n\n");
    printf("\t\t\t============================================\n\n");
    printf("Enter the number of rows you want in your C Pattern: ");
    scanf("%d", &rows);

    space = rows - 1;
    printf("\n\n");

    for (j = 1; j <= rows; j++)
    {
        for (i = 1; i <= space; i++)
            printf(" ");
        space--;
        if (j == 1)
            printf("*");
        else
        {
            printf("*");
            for (i = 1; i <= 2 * j - 3; i++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }

    space = 1;
    for (j = 1; j <= rows - 1; j++)
    {
        for (i = 1; i <= space; i++)
            printf(" ");
        space++;
        printf("*");
        for (i = 1; i <= 2 * (rows - j) - 3; i++)
            printf(" ");
        if (j != rows - 1)
            printf("*");
        printf("\n");
    }

    printf("\n\n\t\t\t============================================\n\n");
    printf("\t\t\tThanks for using our C Pattern Printing Program!\n\n");
    return 0;
}