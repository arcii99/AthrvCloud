//FormAI DATASET v1.0 Category: Pattern printing ; Style: optimized
#include <stdio.h>

int main()
{
    int i, j, n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==1 || i==n || j==1 || j==n)
                printf("*");
            else if(i==j || i==n-j+1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}