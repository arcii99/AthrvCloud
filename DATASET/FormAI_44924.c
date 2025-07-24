//FormAI DATASET v1.0 Category: Pattern printing ; Style: brave
#include <stdio.h>
int main()
{
    int height, space, i, j;
    printf("Enter the height of C : ");
    scanf("%d",&height);
    printf("\n");
    space = height / 2 + 1;
    for(i=1;i<=height;i++)
    {
        for(j=1;j<=space;j++)
        {
            if(i==1 && j==1)
                printf("  * ");
            else if(i==height && j==1)
                printf("  *");
            else if(i>1 && i<height && j==1)
                printf(" * ");
            else if(i==1 && j>1 && j<=space-1)
                printf(" * ");
            else if(i==height && j>1 && j<space)
                printf(" * ");
            else
                printf("   ");
        }
        printf("\n");
    }
    return 0;
}