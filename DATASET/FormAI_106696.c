//FormAI DATASET v1.0 Category: Pattern printing ; Style: random
#include <stdio.h>

int main() {
    int n=7;
    for(int i=1;i<=n;i++)
    {
        if(i==1 || i==n){
            for(int j=1;j<=10;j++)
            {
                printf("* ");
            }
        }
        else if(i==n/2+1)
        {
            for(int j=1;j<=10;j++)
            {
                if(j==1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
        }
        else
        {
            for(int j=1;j<=10;j++)
            {
                if(j==1 || j==10)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}