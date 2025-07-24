//FormAI DATASET v1.0 Category: Pattern printing ; Style: mind-bending
#include<stdio.h>
int main()
{
    int n,i,j,k,s;
    printf("Enter the number of rows: ");
    scanf("%d",&n);                         //take input from user
    s=(n*(n+1))/2;                          //calculate the total number of elements

    for(i=1;i<=n;i++)                       //loop for rows
    {
        for(j=1;j<=s;j++)                   //loop for columns
        {
            if(j<=i || j>s-i)               //condition to print stars
                printf("*");                //printing a star
            else
                printf(" ");                //printing spaces
        }                                   //end of for loop for columns
        printf("\n");                       //move to the next line
    }                                       //end of loop for rows
    return 0;                               //end of main function
}