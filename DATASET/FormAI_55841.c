//FormAI DATASET v1.0 Category: Pattern printing ; Style: brave
#include<stdio.h>
int main()
{
    int n,i,j,k,x;
    n=7;

    // Code to print BRAVE in C pattern
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==n/2)
            {
                printf("B");
                for(x=0;x<2;x++)
                {
                    printf(" ");
                }
                printf("R");
                for(x=0;x<2;x++)
                {
                    printf(" ");
                }
                printf("A");
                for(x=0;x<2;x++)
                {
                    printf(" ");
                }
                printf("V");
                for(x=0;x<2;x++)
                {
                    printf(" ");
                }
                printf("E ");
                break;
            }

            else if(j==0 || j==n-1)
            {
                printf("B ");
            }
            else if(j==1 || j==n-2)
            {
                printf("R ");
            }
            else if(j==2 || j==n-3)
            {
                printf("A ");
            }
            else if(j==3 || j==n-4)
            {
                printf("V ");
            }
            else if(j==4)
            {
                printf("E ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}