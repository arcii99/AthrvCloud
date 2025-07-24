//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include<stdio.h>
void pattern(int n, int s)
{
    int i,j;
    if(n>0)
    {
        pattern(n-1,s+1);
        for(i=1; i<=s; i++)
        {
            printf(" ");
        }
        for(j=1; j<=n; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the number of rows in the pattern: ");
    scanf("%d",&n);
    pattern(n,0);
    return 0;
}