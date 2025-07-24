//FormAI DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

int main()
{
    int m, n, i, j, choice;
    complex double **mat1, **mat2, **result;

    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    mat1 = (complex double**)malloc(m * sizeof(complex double*));
    mat2 = (complex double**)malloc(m * sizeof(complex double*));
    result = (complex double**)malloc(m * sizeof(complex double*));

    for(i = 0; i < m; i++)
    {
        mat1[i] = (complex double*)malloc(n * sizeof(complex double));
        mat2[i] = (complex double*)malloc(n * sizeof(complex double));
        result[i] = (complex double*)malloc(n * sizeof(complex double));
    }

    printf("Enter matrix 1: \n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter element a[%d][%d]: ", i+1, j+1);
            scanf("%lf%lf", &mat1[i][j]);
        }
    }

    printf("\nEnter matrix 2: \n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter element a[%d][%d]: ", i+1, j+1);
            scanf("%lf%lf", &mat2[i][j]);
        }
    }

    printf("\nChoose one of the following operations: \n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            for(i = 0; i < m; i++)
            {
                for(j = 0; j < n; j++)
                {
                    result[i][j] = mat1[i][j] + mat2[i][j];
                }
            }
            printf("\nResultant matrix after addition is: \n");
            break;

        case 2:
            for(i = 0; i < m; i++)
            {
                for(j = 0; j < n; j++)
                {
                    result[i][j] = mat1[i][j] - mat2[i][j];
                }
            }
            printf("\nResultant matrix after subtraction is: \n");
            break;

        case 3:
            for(i = 0; i < m; i++)
            {
                for(j = 0; j < n; j++)
                {
                    result[i][j] = 0;
                    for(int k = 0;k < n;k++){
                      result[i][j] += (mat1[i][k] * mat2[k][j]);
                    }
                }
            }
            printf("\nResultant matrix after multiplication is: \n");
            break;

        default:
            printf("Invalid choice.\n");
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%lf + %lfi\t", creal(result[i][j]), cimag(result[i][j]));
        }
        printf("\n");
    }

    return 0;
}