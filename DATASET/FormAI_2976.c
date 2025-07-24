//FormAI DATASET v1.0 Category: Pattern printing ; Style: thoughtful
#include<stdio.h>

int main()
{
    int size, i, j;
    printf("Enter the size of the pattern: ");
    scanf("%d",&size);

    for(i=1;i<=size;i++) //loop to print the upper half of the pattern
    {
        for(j=1;j<=size-i;j++) //loop to print blank spaces
        {
            printf("  ");
        }
        for(j=1;j<=(2*i-1);j++) //loop to print asterisks
        {
            printf("* ");
        }
        printf("\n"); //going to the next line
    }

    for(i=size-1;i>=1;i--) //loop to print the lower half of the pattern
    {
        for(j=1;j<=size-i;j++) //loop to print blank spaces
        {
            printf("  ");
        }
        for(j=1;j<=(2*i-1);j++) //loop to print asterisks
        {
            printf("* ");
        }
        printf("\n"); //going to the next line
    }

    return 0; //end of the program
}