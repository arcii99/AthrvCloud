//FormAI DATASET v1.0 Category: Pattern printing ; Style: enthusiastic
#include<stdio.h>
int main()
{
    int num, i, j, space;
    printf("Enter the number of rows: ");
    scanf("%d", &num);
    for(i=1;i<=num;i++)
    {
        for(space=i;space<num;space++)
            printf(" ");
        for(j=1;j<=((i*2)-1);j++)
            printf("*");
        printf("\n");
    }
    for(i=num-1;i>=1;i--)
    {
        for(space=num;space>i;space--)
            printf(" ");
        for(j=1;j<=(i*2)-1;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}