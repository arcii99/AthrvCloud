//FormAI DATASET v1.0 Category: Pattern printing ; Style: automated
#include <stdio.h>

int main()
{
    int n = 5; // change this value to adjust size of pattern
    
    // upper half of pattern
    for (int i=1; i<=n; i++)
    {
        for (int j=n-i+1; j>=1; j--)
            printf("%d ", j);
        printf("\n");
    }
    
    // lower half of pattern
    for (int i=2; i<=n; i++)
    {
        for (int j=1; j<=n-i+1; j++)
            printf("%d ", j);
        printf("\n");
    }
    
    return 0;
}