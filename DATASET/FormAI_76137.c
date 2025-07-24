//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

int main()
{
    int i,j,k,l;
    for(i=1;i<=5;i++) //creating upper part of C
    {
        for(j=1;j<=5;j++)
        {
            if(i==1||j==1)
                printf("*");
            else
                printf(" ");
        }
    printf("\n");
    }

    for(k=1;k<=3;k++) //creating lower part of C
    {
        for(l=1;l<=5;l++)
        {
            if(k==3||l==1)
                printf("*");
            else
                printf(" ");
        }
    printf("\n");
    }

    return 0;
}