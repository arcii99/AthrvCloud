//FormAI DATASET v1.0 Category: Pattern printing ; Style: mathematical
#include <stdio.h>

int main()
{
    int n = 10;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == 1 || i == n || j == 1 || j == n || i == j || i == n - j + 1)
            {
                printf("* ");
            }
            else if(i > j && i > n - j + 1)
            {
                printf("%d ", i + j - n - 1);
            }
            else if(i > j && i < n - j + 1)
            {
                printf("%d ", j);
            }
            else if(i < j && i > n - j + 1)
            {
                printf("%d ", n - j + 1);
            }
            else if(i < j && i < n - j + 1)
            {
                printf("%d ", i + j - 1);
            }
        }
        printf("\n");
    }
    
    return 0;
}