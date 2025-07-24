//FormAI DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &num);

    for(i=1;i<=num;i++)
    {
        for(j=num;j>i;j--)
        {
            printf(" ");
        }
        for(j=1;j<=i*2-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=num-1;i>=1;i--)
    {
        for(j=num;j>i;j--)
        {
            printf(" ");
        }
        for(j=1;j<=i*2-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}