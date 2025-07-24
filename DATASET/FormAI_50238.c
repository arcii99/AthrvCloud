//FormAI DATASET v1.0 Category: Pattern printing ; Style: Sherlock Holmes
#include<stdio.h>

int main()
{
    printf("Mr. Sherlock Holmes\n\n");
    printf("The Case of the Unique C Pattern\n\n");

    int rows, i, j, k, space;

    printf("Enter the number of rows : ");
    scanf("%d", &rows);

    printf("\n");

    space = rows - 1;
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= space; j++)
            printf(" ");

        space--;

        for (k = 1; k <= 2 * i - 1; k++)
        {
            if (i == 1 || i == rows || k == 1 || k == 2 * i - 1)
                printf("*");
            else
                printf("C");
        }
        printf("\n");
    }

    printf("\nSolved by Mr. Sherlock Holmes\n");

    return 0;
}