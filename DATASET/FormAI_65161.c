//FormAI DATASET v1.0 Category: Pattern printing ; Style: standalone
#include <stdio.h>

int main()
{
    int n,i,j;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    if(n<=0){
        printf("Please enter a positive number greater than 0.\n");
        return 0;
    }
    else{
        //Print first half of pattern
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n-i+1;j++)
            {
                printf("%d",j);
            }
            printf("\n");
        }
        //Print second half of pattern
        for(i=n-1;i>=1;i--)
        {
            for(j=1;j<=n-i+1;j++)
            {
                printf("%d",j);
            }
            printf("\n");
        }   
    }
    return 0;
}