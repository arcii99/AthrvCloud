//FormAI DATASET v1.0 Category: Matrix operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to print the matrix
void print_matrix(int rows, int cols, int matrix[][cols])
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int rows, int cols, int matrix1[][cols], int matrix2[][cols])
{
    int result[rows][cols];
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("The sum of the matrices is:\n");
    print_matrix(rows, cols, result);
}

// Function to multiply two matrices
void multiply_matrices(int rows1, int cols1, int matrix1[][cols1], int rows2, int cols2, int matrix2[][cols2])
{
    int result[rows1][cols2];
    for(int i=0; i<rows1; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            result[i][j] = 0;
            for(int k=0; k<cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("The product of the matrices is:\n");
    print_matrix(rows1, cols2, result);    
}

int main()
{
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns of Matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the elements of Matrix 1:\n");
    int matrix1[rows1][cols1];
    for(int i=0; i<rows1; i++)
    {
        for(int j=0; j<cols1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the number of rows and columns of Matrix 2: ");
    scanf("%d %d", &rows2, &cols2);
    if(cols1 != rows2)
    {
        printf("Error: The number of columns in Matrix 1 should be equal to the number of rows in Matrix 2.\n");
        exit(0);
    }
    printf("Enter the elements of Matrix 2:\n");
    int matrix2[rows2][cols2];
    for(int i=0; i<rows2; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("Matrix 1:\n");
    print_matrix(rows1, cols1, matrix1);
    printf("Matrix 2:\n");
    print_matrix(rows2, cols2, matrix2);
    add_matrices(rows1, cols1, matrix1, matrix2);
    multiply_matrices(rows1, cols1, matrix1, rows2, cols2, matrix2);
    return 0;
}