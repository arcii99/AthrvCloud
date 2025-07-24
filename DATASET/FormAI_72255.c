//FormAI DATASET v1.0 Category: Pattern printing ; Style: minimalist
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the pattern: ");
    scanf("%d",&n);
    int mid = (n%2==0)?n/2:(n+1)/2;
    //top triangle
    for(int i=1;i<=mid;i++)
    {
        for(int j=1;j<=n-i+1;j++)
            printf("*");
        for(int j=1;j<=2*(i-1);j++)
            printf(" ");
        for(int j=1;j<=n-i+1;j++)
            printf("*");
        printf("\n");
    }
    //bottom triangle
    for(int i=mid+1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            printf("*");
        for(int j=1;j<=2*(n-i);j++)
            printf(" ");
        for(int j=1;j<=i;j++)
            printf("*");
        printf("\n");
    }

    return 0;
}