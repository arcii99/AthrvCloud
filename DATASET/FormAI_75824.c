//FormAI DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include<stdio.h>

int main()
{
    int n, i, j, k;

    //Taking input from user
    printf("Enter the number of lines for C pattern: ");
    scanf("%d", &n);

    //Printing C pattern
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==1 || i==n || j==1)
            {
                //Printing C character
                printf("C");
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