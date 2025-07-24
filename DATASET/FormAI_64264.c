//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>
void main()
{
    int i, j, n, m;
    printf("\n Enter the number of rows: ");
    scanf("%d",&n);
    m = n / 2 + 1;
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf(" C ");
        }
        printf("\n");
    }
    for(i = m; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            printf(" C ");
        }
        printf("\n");
    }
    printf("\n\n ~~~Yay! Enjoy the pattern~~~");
}