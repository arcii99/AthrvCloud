//FormAI DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, count = 0;
    printf("Enter the number of rows you want: ");
    scanf("%d", &num);
    for(int i = 1; i <= num; i++)
    {
        for(int j = 1; j <= num; j++)
        {
            if(j == i || j == num - i + 1)
            {
                printf(" *");
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