//FormAI DATASET v1.0 Category: Recursive ; Style: Cyberpunk
#include <stdio.h>

void MatrixMultiply(int matrix1[][3], int matrix2[][3], int result[][3], int row, int col)
{
    int i, j, k;
    int sum = 0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            for(k=0;k<3;k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
    }
}

void MatrixInverse(int matrix[][3], int inverse[][3], int row, int col)
{
    int det = (matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]))) - (matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]))) + (matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0])));
    int temp[3][3];
    temp[0][0] = ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1])) / det; 
    temp[0][1] = ((matrix[0][2] * matrix[2][1]) - (matrix[0][1] * matrix[2][2])) / det;  
    temp[0][2] = ((matrix[0][1] * matrix[1][2]) - (matrix[0][2] * matrix[1][1])) / det;  
    temp[1][0] = ((matrix[1][2] * matrix[2][0]) - (matrix[1][0] * matrix[2][2])) / det;  
    temp[1][1] = ((matrix[0][0] * matrix[2][2]) - (matrix[0][2] * matrix[2][0])) / det;  
    temp[1][2] = ((matrix[1][0] * matrix[0][2]) - (matrix[0][0] * matrix[1][2])) / det;  
    temp[2][0] = ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0])) / det;  
    temp[2][1] = ((matrix[0][1] * matrix[2][0]) - (matrix[0][0] * matrix[2][1])) / det;  
    temp[2][2]= ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0])) / det;  
    MatrixMultiply(temp, matrix, inverse, row, col);
}

int main()
{
    printf("Hacker, welcome to the matrix!\n");

    int matrix[3][3] = {{2, 1, 4}, {1, 0, 3}, {5, 7, 6}};
    int determinant = (matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]))) - (matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]))) + (matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0])));
    printf("The determinant of the matrix is: %d\n", determinant);

    int adj[3][3];
    adj[0][0] = ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]));  
    adj[0][1] = -((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]));  
    adj[0][2] = ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]));  
    adj[1][0] = -((matrix[0][1] * matrix[2][2]) - (matrix[0][2] * matrix[2][1]));   
    adj[1][1] = ((matrix[0][0] * matrix[2][2]) - (matrix[0][2] * matrix[2][0]));   
    adj[1][2] = -((matrix[0][0] * matrix[2][1]) - (matrix[0][1] * matrix[2][0]));  
    adj[2][0] = ((matrix[0][1] * matrix[1][2]) - (matrix[0][2] * matrix[1][1]));   
    adj[2][1] = -((matrix[0][0] * matrix[1][2]) - (matrix[0][2] * matrix[1][0]));   
    adj[2][2] = ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));   

    printf("The adjoint of the matrix is:\n");
    int i, j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("The inverse of the matrix is:\n");
    int inverse[3][3];
    MatrixInverse(matrix, inverse, 3, 3);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ", inverse[i][j]);
        }
        printf("\n");
    }

    printf("All codes are executed successfully. We are done here!\n");
    return 0;
}