//FormAI DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

int main()
{
    int rows, i, j, k;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for(i=1; i<=rows; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
        for(k=i; k<rows; k++)
        {
            printf(" ");
        }
        for(k=i; k<rows; k++)
        {
            printf(" ");
        }
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for(i=rows; i>=1; i--)
    {
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
        for(k=i; k<rows; k++)
        {
            printf(" ");
        }
        for(k=i; k<rows; k++)
        {
            printf(" ");
        }
        for(j=1; j<=i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}