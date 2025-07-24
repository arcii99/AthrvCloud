//FormAI DATASET v1.0 Category: Pattern printing ; Style: portable
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    if (n % 2 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == n - 1 || j == 0)
                {
                    printf("*");
                }
                else if (i == j)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("Please enter an odd number of rows.\n");
    }

    return 0;
}