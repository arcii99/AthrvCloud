//FormAI DATASET v1.0 Category: Pattern printing ; Style: romantic
#include <stdio.h>

int main()
{
    int i, j, k;
    char arr[] = "ILoveYou";
    int len = strlen(arr);

    for(i=1; i<=6; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("%c ", arr[j-1]);
        }
        for(k=1; k<=(6-i); k++)
        {
            printf("  ");
        }
        for(j=i; j>=1; j--)
        {
            printf("%c ", arr[j-1]);
        }
        printf("\n");
    }

    for(i=len-1; i>=1; i--)
    {
        for(j=1; j<=i; j++)
        {
            printf("%c ", arr[j-1]);
        }
        for(k=1; k<=(len-i); k++)
        {
            printf("  ");
        }
        for(j=i; j>=1; j--)
        {
            printf("%c ", arr[j-1]);
        }
        printf("\n");
    }

    return 0;
}