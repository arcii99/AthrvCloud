//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n");
    for(int i=0;i<10;i++) // Upper Triangular Pattern
    {
        for(int j=0;j<=i;j++)
        {
            printf("%d ", j+1);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<10;i++) // Lower Triangular Pattern
    {
        for(int j=0;j<=i;j++)
        {
            printf("%d ", i+1-j);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<10;i++) // Pyramid Pattern
    {
        for(int k=10-i;k>0;k--)
        {
            printf(" ");
        }
        for(int j=0;j<=i;j++)
        {
            printf("%d ", i-j+1);
        }
        for(int m=0;m<i;m++)
        {
            printf("%d ", m+2);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<5;i++) // Diamond Pattern
    {
        for(int k=4-i;k>0;k--)
        {
            printf(" ");
        }
        for(int j=0;j<=i;j++)
        {
            printf("%d ", j+1);
        }
        for(int m=0;m<i;m++)
        {
            printf("%d ", i-m);
        }
        printf("\n");
    }
    for(int i=0;i<4;i++)
    {
        for(int k=0;k<=i;k++)
        {
            printf(" ");
        }
        for(int j=0;j<4-i;j++)
        {
            printf("%d ", j+1);
        }
        for(int m=3-i;m>0;m--)
        {
            printf("%d ", m);
        }
        printf("\n");
    }
    return 0;
}