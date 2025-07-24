//FormAI DATASET v1.0 Category: Pattern printing ; Style: optimized
#include <stdio.h>
int main()
{
    int i, j, k, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = n; j > i; j--)
        {
            printf(" ");  // prints spaces before the pattern
        }
        for (k = 1; k <= i; k++)
        {
            printf("* ");  // prints the pattern
        }
        printf("\n");  // moves to the next row
    }
    return 0;
}