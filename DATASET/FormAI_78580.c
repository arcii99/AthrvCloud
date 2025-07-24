//FormAI DATASET v1.0 Category: Pattern printing ; Style: thoughtful
#include <stdio.h>

int main()
{
    int height, width, i, j, k;

    printf("Enter the height and width of the pattern: ");
    scanf("%d %d", &height, &width);

    //Top half of the pattern
    for(i=0; i<height; i++)
    {
        for(j=0; j<(height-i-1); j++)
        {
            printf(" ");
        }
        for(k=0; k<(2*i+1); k++)
        {
            printf("*");
        }
        printf("\n");
    }

    //Bottom half of the pattern
    for(i=height-2; i>=0; i--)
    {
        for(j=0; j<(height-i-1); j++)
        {
            printf(" ");
        }
        for(k=0; k<(2*i+1); k++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}