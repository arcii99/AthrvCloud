//FormAI DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>

int main()
{
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int i, j, k, m, n, p, q;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &m, &n);
    printf("Enter elements of first matrix:\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &matrix1[i][j]);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &p, &q);
    if(n != p)
    {
        printf("Matrices can't be multiplied!");
        return 0;
    }
    printf("Enter elements of second matrix:\n");
    for(i=0; i<p; i++)
        for(j=0; j<q; j++)
            scanf("%d", &matrix2[i][j]);

    for(i=0; i<m; i++)
    {
        for(j=0; j<q; j++)
        {
            result[i][j] = 0;
            for(k=0; k<n; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }

    printf("Product of the matrices:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<q; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    return 0;
}