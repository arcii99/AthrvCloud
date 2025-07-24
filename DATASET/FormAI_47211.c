//FormAI DATASET v1.0 Category: Pattern printing ; Style: energetic
#include<stdio.h>
int main()
{
    printf("Get ready to witness the power of C in Pattern Printing! \n\n");
    int rows;
    printf("Enter the number of rows you want! ");
    scanf("%d",&rows);

    printf("\nLet's get started!\n\n");

    int i,j,k=0;
    for(i=1;i<=rows;i++)
    {
        // Spaces before the pattern
        for(j=i;j<rows;j++)
        {
            printf("  ");
        }
        //Print the pattern
        while(k!=(2*i-1))
        {
            printf("* ");
            k++;
        }
        k=0;
        printf("\n");//New line after each row gets printed
    }
    //Generating the lower part of the pattern
    for(i=rows-1;i>=1;i--)
    {
        // Spaces before the pattern
        for(j=rows;j>i;j--)
        {
            printf("  ");
        }
        //Print the pattern
        k=0;
        while(k!=(2*i-1))
        {
            printf("* ");
            k++;
        }
        printf("\n");//New line after each row gets printed
    }
    printf("\nThe pattern in C is completed! \n");
    return 0;
}