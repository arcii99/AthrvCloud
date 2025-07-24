//FormAI DATASET v1.0 Category: Pattern printing ; Style: inquisitive
#include<stdio.h>

int main()
{
    int rows, cols, i, j; //declare variables

    printf("Enter the number of rows: "); //ask user for number of rows
    scanf("%d",&rows);

    printf("Enter the number of columns: "); //ask user for number of columns
    scanf("%d",&cols);

    for(i=1;i<=rows;i++) //loop for each row
    {
        for(j=1;j<=cols;j++) //loop for each column 
        {
            if(i==1 || i==rows || j==1 || j==cols) //condition to print pattern based on border
            {
                printf("*");
            }
            else if(i%2==0 && j%2==0) //condition to print pattern based on even rows and columns
            {
                printf("+");
            }
            else if(i%2==1 && j%2==1) //condition to print pattern based on odd rows and columns
            {
                printf("-");
            }
            else //condition to print blank spaces
            {
                printf(" ");
            }
        }
        printf("\n"); //move to next line after each row
    }

    return 0; //program success
}