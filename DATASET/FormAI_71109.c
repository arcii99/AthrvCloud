//FormAI DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>

// Function to print the matrix
void printMatrix(int M[][3], int row, int col)
{
    printf("The matrix is:\n");
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the transpose of the matrix
void transposeMatrix(int M[][3], int row, int col)
{
    int transpose[col][row];
 
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            transpose[i][j] = M[j][i];
        }
    }
 
    printf("The transpose of the matrix is:\n");
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the determinant of a 2x2 matrix
int determinant(int M[][2])
{
    int det = (M[0][0] * M[1][1]) - (M[0][1] * M[1][0]);
    return det;
}

// Function to calculate the inverse of a 2x2 matrix
void inverseMatrix(int M[][2])
{
    int det = determinant(M);

    if (det == 0)
    {
        printf("The matrix is singular and the inverse cannot be found.\n");
    }
    else
    {
        int inverse[2][2];

        inverse[0][0] = M[1][1] / det;
        inverse[0][1] = -(M[0][1] / det);
        inverse[1][0] = -(M[1][0] / det);
        inverse[1][1] = M[0][0] / det;

        printf("The inverse of the matrix is:\n");
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                printf("%d\t", inverse[i][j]);
            }
            printf("\n");
        }
    }
}

// Main function
int main()
{
    int M[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
    int M2[2][2] = {{2, 7}, 
                    {1, 3}};

    // Print the original matrix
    printMatrix(M, 3, 3);

    // Calculate the transpose of the matrix
    transposeMatrix(M, 3, 3);

    // Calculate the determinant of the matrix
    int det = determinant(M2);
    printf("The determinant of the matrix is: %d\n", det);

    // Calculate the inverse of the matrix
    inverseMatrix(M2);

    return 0;
}