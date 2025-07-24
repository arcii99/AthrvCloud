//FormAI DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>
int main() {
    int rows, i, j, k, l, space = 0;
    printf("Enter the number of rows:\n");
    scanf("%d", &rows);
    printf("\n");
    for (i=1; i<=rows; i++)
    {
        // First Part of the Pattern
        for (j=1; j<=i; j++) 
        {
            printf("* ");
        }
        // Spaces between the First and Second Part of the Pattern
        for (k=i+1; k<=rows; k++) 
        {
            printf("  ");
        }
        // Second Part of the Pattern
        for (l=rows-i+1; l>=1; l--) 
        {
            printf("* ");
        }
        printf("\n");
    }
    for (i=rows; i>=1; i--)
    {
        // First Part of the Pattern
        for (j=1; j<=i; j++) 
        {
            printf("* ");
        }
        // Spaces between the First and Second Part of the Pattern
        for (k=rows-i+1; k<=rows; k++) 
        {
            printf("  ");
        }
        // Second Part of the Pattern
        for (l=1; l<=i; l++) 
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}