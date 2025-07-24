//FormAI DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>

int main()
{
    int rows = 11;
    int cols = 11;
    int i, j;
    printf("\n");

    for(i=1; i<=rows; i++)
    {
        for(j=1; j<=cols; j++)
        {
            if(i==1 && j==6)
                printf("*");
            else if(i==2 && (j==5 || j==7))
                printf("*");
            else if(i==3 && (j==4 || j==8))
                printf("*");
            else if(i==4 && (j==3 || j==9))
                printf("*");
            else if(i==5 && (j==2 || j==10))
                printf("*");
            else if(i==6 && (j==1 || j==11))
                printf("*");
            else if(i>=7 && i<=11 && (j>=i-5 && j<=16-i))
                 printf("*");
            else if(i>=5 && i<=7 && j==6)
                printf("*");
            else if(i==12 && (j==6 || j==5 || j==7))
                printf("*");
            else if(i==13 && (j==5 || j==7))
                printf("*");
            else if(i==14 && j==6)
                printf("*");
            else if(i>=15 && i<=19 && j==6)
                printf("*");
            else if(i>=15 && i<=19 && (j>=23-i && j<=i-15))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}