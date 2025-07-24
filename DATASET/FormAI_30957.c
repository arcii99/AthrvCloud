//FormAI DATASET v1.0 Category: Pattern printing ; Style: multivariable
#include <stdio.h>

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    for(int i = num; i >= 1; i--)
    {
        // Print the spaces
        for(int j = 1; j <= num - i; j++)
        {
            printf(" ");
        }

        // Print the stars
        for(int j = 1; j <= i; j++)
        {
            printf("* ");
        }

        printf("\n");
    }

    for(int i = 1; i <= num; i++)
    {
        // Print the spaces
        for(int j = 1; j <= num - i; j++)
        {
            printf(" ");
        }

        // Print the stars
        for(int j=1; j <= i; j++)
        {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}