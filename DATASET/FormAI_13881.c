//FormAI DATASET v1.0 Category: Pattern printing ; Style: innovative
#include <stdio.h>

int main()
{
    int i, j, size;
    
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);
    
    for(i=1; i<=size/2+1; i++)
    {
        for(j=1; j<=2*i-1; j++)
        {
            if(j%2 == 0)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
    
    for(i=size/2; i>=1; i--)
    {
        for(j=1; j<=2*i-1; j++)
        {
            if(j%2 == 0)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
    
    return 0;
}