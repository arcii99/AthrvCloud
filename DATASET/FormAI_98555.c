//FormAI DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, n;
    printf("Enter the value of n: ");
    scanf("%d",&n);

    // First half of the pattern
    for(i=1;i<=n;i++)
    {
        for(j=n;j>=i;j--)
        {
            printf("* ");
        }
        for(k=1;k<=(2*i-2);k++)
        {
            printf("  ");
        }
        for(j=n;j>=i;j--)
        {
            printf("* ");
        }
        printf("\n");
    }
    
    // Second half of the pattern
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=i+1;j++)
        {
            printf("* ");
        }
        for(k=(2*n-4);k>=2*i;k--)
        {
            printf("  ");
        }
        for(j=i+1;j>=1;j--)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}