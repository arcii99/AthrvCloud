//FormAI DATASET v1.0 Category: Pattern printing ; Style: bold
#include<stdio.h>

int main()
{
    int i, j, n;
    printf("Enter the no of rows for the pattern: ");
    scanf("%d",&n);

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
        {
            if(i==1 || i==n || j==1 || j==n || i==j || j==(n-i+1))
            {
                printf("\033[1m*\033[0m");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}