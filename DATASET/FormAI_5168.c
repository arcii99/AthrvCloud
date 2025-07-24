//FormAI DATASET v1.0 Category: Pattern printing ; Style: Ken Thompson
#include<stdio.h>
int main()
{
    int i,j,k;
    for(i=1;i<=7;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=6;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=1;i<=7;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf(" ");
        }
        for(k=7-i;k>=1;k--)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=6;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            printf(" ");
        }
        for(k=7-i;k>=1;k--)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}