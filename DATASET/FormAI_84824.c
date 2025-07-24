//FormAI DATASET v1.0 Category: Matrix operations ; Style: Alan Touring
#include <stdio.h>

int main()
{
    int rows, cols, i, j;
    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d %d", &rows, &cols);

    int mat1[rows][cols], mat2[rows][cols], sum[rows][cols];

    printf("Enter the elements of first matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the elements of second matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("The sum of the matrices is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}