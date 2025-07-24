//FormAI DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>

int main()
{
    // Initialize variables
    int row1, col1, row2, col2, i, j, k;
    
    // Ask user for matrix dimensions
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d",&row1,&col1);
    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d",&row2,&col2);
    
    // Check dimensions for matrix multiplication
    if(col1 != row2)
    {
        printf("Error! The matrices cannot be multiplied.");
        return 0;
    }
    
    // Declare matrices
    int matrix1[row1][col1], matrix2[row2][col2], product[row1][col2];
    
    // Ask user for matrix values
    printf("\nEnter the values of matrix 1:\n");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col1;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("\nEnter the values of matrix 2:\n");
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    
    // Multiply matrices and store in product array
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col2;j++)
        {
            product[i][j] = 0;
            for(k=0;k<col1;k++)
            {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    // Display product matrix
    printf("\nThe product of the matrices is:\n");
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col2;j++)
        {
            printf("%d\t",product[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}