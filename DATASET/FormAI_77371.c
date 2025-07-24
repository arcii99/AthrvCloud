//FormAI DATASET v1.0 Category: Educational ; Style: complex
#include<stdio.h>

int main()
{
    int i, j, n, k=0;
    printf("Enter the number of rows\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=i;j<n;j++)
        {
            printf(" ");
        }
        while(k!=(2*i-1))
        {
            if(k==0 || k==2*i-2 || i==n)
                printf("*");
            else
                printf(" ");
            k++;
        }
        k=0;
        printf("\n");
    }
    for(i=n;i>=1;i--)
    {
        for(j=i;j<=n;j++)
        {
            printf(" ");
        }
        while(k!=(2*i-1))
        {
            if(k==0 || k==2*i-2 || i==n)
                printf("*");
            else
                printf(" ");
            k++;
        }
        k=0;
        printf("\n");
    }
    return 0;
}