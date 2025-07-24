//FormAI DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare Variables
    int A[10][10], B[10][10], C[10][10], D[10][10];
    int rows, cols, i, j;

    // Generate Random Matrix A
    srand(time(0));
    rows = rand()%5 + 5; // Random Number of Rows
    cols = rand()%5 + 5; // Random Number of Columns
    printf("Matrix A: %d x %d\n", rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            A[i][j] = rand()%10 + 1; // Random Number between 1 and 10
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Generate Random Matrix B
    srand(time(0));
    rows = rand()%5 + 5; // Random Number of Rows
    cols = rand()%5 + 5; // Random Number of Columns
    printf("Matrix B: %d x %d\n", rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            B[i][j] = rand()%10 + 1; // Random Number between 1 and 10
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Calculate Matrix C
    if (A[0][0] == 1 && A[0][1] == 0 && B[0][0] == 0 && B[1][0] == 1)
    {
        printf("Eigenvalue = 4\n");
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                C[i][j] = A[i][j] * B[i][j];
            }
        }
    }
    else if (A[0][0] == 0 && A[1][0] == 1 && B[0][1] == 1 && B[1][0] == 0)
    {
        printf("Eigenvalue = 10\n");
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }
    else
    {
        printf("Eigenvalue = 1\n");
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                C[i][j] = A[i][j] - B[i][j];
            }
        }
    }

    // Display Matrix C
    printf("Matrix C: %d x %d\n", rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Calculate Matrix D
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            D[i][j] = C[i][j] * C[i][j];
        }
    }

    // Display Matrix D
    printf("Matrix D: %d x %d\n", rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}