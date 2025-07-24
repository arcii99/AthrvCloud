//FormAI DATASET v1.0 Category: Pattern printing ; Style: peaceful
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    printf("\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            printf("  ");
        }
        int val=i;
        for(int j=1;j<=i;j++)
        {
            printf("%d ",val);
            val--;
        }
        val=2;
        for(int j=1;j<i;j++)
        {
            printf("%d ",val);
            val++;
        }
        printf("\n");
    }
    return 0;
}