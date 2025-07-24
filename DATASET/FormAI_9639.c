//FormAI DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("\n");

    // Print the pattern
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                printf("%-2d ", i);
            }
            else if(i == n - j + 1)
            {
                printf("%-2d ", j);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}