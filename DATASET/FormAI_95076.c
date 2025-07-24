//FormAI DATASET v1.0 Category: Matrix operations ; Style: medieval
#include <stdio.h>
#define SIZE 3 // size of the matrix

// Perform Matrix Multiplication
void matrixMult(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result[SIZE][SIZE])
{
    int i, j, k;
    for (i = 0; i < SIZE; ++i)
    {
        for (j = 0; j < SIZE; ++j)
        {
            result[i][j] = 0;
            for (k = 0; k < SIZE; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Print the Matrix
void printMatrix(int matrix[SIZE][SIZE])
{
    int i, j;
    printf("The Matrix is:\n");
    for (i = 0; i < SIZE; ++i)
    {
        for (j = 0; j < SIZE; ++j)
        {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

// It computes the determinant of the matrix recursively
int determinant(int matrix[SIZE][SIZE], int n)
{
    int det = 0;
    int subMatrix[SIZE][SIZE];
    if (n == 2)
    {
        return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
    }
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0; // submatrix's i value
            for (int i = 1; i < n; i++)
            {
                int subj = 0; // submatrix's j value
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    subMatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant(subMatrix, n - 1));
        }
        return det;
    }
}

int main()
{
    int matrix1[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[SIZE][SIZE] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[SIZE][SIZE], determinantResult;
    matrixMult(matrix1, matrix2, result);
    printf("The result of the matrix multiplication:\n");
    printMatrix(result);
    determinantResult = determinant(matrix1, SIZE);
    printf("\nThe determinant of the matrix is: %d", determinantResult);
    return 0;
}