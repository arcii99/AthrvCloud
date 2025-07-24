//FormAI DATASET v1.0 Category: Pattern printing ; Style: brave
#include <stdio.h>

int main()
{
    printf("\t\t\tC Pattern Printing Program\n\n");

    for(int i=1;i<=5;i++)
    {
        for(int j=5;j>=i;j--)
        {
            printf("%d ",j);
        }
        for(int k=1;k<=(i*2-1);k++)
        {
            printf("*");
        }
        for(int l=i;l<=5;l++)
        {
            printf(" %d",l);
        }
        printf("\n");
    }

    for(int i=4;i>=1;i--)
    {
        for(int j=5;j>=i;j--)
        {
            printf("%d ",j);
        }
        for(int k=1;k<=(i*2-1);k++)
        {
            printf("*");
        }
        for(int l=i;l<=5;l++)
        {
            printf(" %d",l);
        }
        printf("\n");
    }

    return 0;
}