//FormAI DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>

int main()
{
    int i, j, n;    // variables declaration
 
    printf("Enter the number of rows: ");
    scanf("%d", &n);
 
    for (i = 1; i <= n; i++)    // loop for rows
    {
        for (j = 1; j <= i; j++)    // loop for columns
        {
            if (j == 1 || j == i || i == n)    // printing "*" for certain conditions
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
 
        printf("\n");    // move to the next line
    }
 
    return 0;
}