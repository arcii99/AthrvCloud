//FormAI DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

int main()
{
    int i, j, k;

    // Top pattern
    for(i=1;i<=5;i++)
    {
        for(j=5;j>=i;j--)
        {
            printf("%d",j);
        }
        for(k=1;k<(i*2);k++)
        {
            printf(" ");
        }
        for(j=i;j<=5;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }

    // Middle pattern
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=6;j++)
        {
            printf(" ");
        }
        for(j=1;j<=3;j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    // Bottom pattern
    for(i=5;i>=1;i--)
    {
        for(j=5;j>=i;j--)
        {
            printf("%d",j);
        }
        for(k=1;k<(i*2);k++)
        {
            printf(" ");
        }
        for(j=i;j<=5;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }

    return 0;
}