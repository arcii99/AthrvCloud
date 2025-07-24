//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include<stdio.h>

int main()
{
    int rows;
    
    printf("Enter the number of rows for the pattern:\n");
    scanf("%d",&rows);
    
    for(int i=1; i<=rows; i++)
    {
        //Printing white spaces
        for(int k=1; k<=rows-i; k++)
        {
            printf(" ");
        }
        //Printing stars
        for(int j=1; j<=(2*i)-1; j++)
        {
            printf("*");
        }
        printf("\n");//Moving to next line
    }

    return 0;
}