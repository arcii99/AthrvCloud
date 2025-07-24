//FormAI DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include<stdio.h>
int main()
{
    int i,j,k;
    char ch = 'A';
    
    printf("\t🎉 WELCOME TO C PATTERN PRINTING 🎉 \n\n");
    
    // PATTERN 1
    printf("PATTERN 1: \n");
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    
    // PATTERN 2
    printf("\nPATTERN 2: \n");
    for(i=1;i<=5;i++)
    {
        for(j=5;j>i;j--)
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)
        {
            printf("%c ",ch++);
        }
        printf("\n");
    }
    
    // PATTERN 3
    printf("\nPATTERN 3: \n");
    for(i=1;i<=5;i++)
    {
        for(j=5;j>i;j--)
        {
            printf(" ");
        }
        for(k=1;k<=(2*i-1);k++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    // PATTERN 4
    printf("\nPATTERN 4: \n");
    for(i=1;i<=5;i++)
    {
        for(j=5;j>i;j--)
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)
        {
            printf("%c ",ch++);
        }
        ch--;
        for(k=1;k<i;k++)
        {
            printf("%c ",--ch);
        }
        printf("\n");
        ch='A';
    }
    
    // PATTERN 5
    printf("\nPATTERN 5: \n");
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            if((i==1 || i==9 || j==1 || j==9) || (i==5 && j>3 && j<7) || (j==5 && i>3 && i<7))
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\n\t🎉 PATTERN PRINTING COMPLETED 🎉 \n");
    return 0;
}