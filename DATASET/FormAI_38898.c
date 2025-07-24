//FormAI DATASET v1.0 Category: Matrix operations ; Style: genious
#include <stdio.h>

int main() {
    int m, n;
    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    int matrix1[m][n], matrix2[m][n], sum[m][n];
    printf("Enter the elements of first matrix:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the elements of second matrix:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Elements of first matrix:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Elements of second matrix:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("Sum of the matrices:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    int transpose[n][m];
    printf("Transpose of the first matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            transpose[i][j] = matrix1[j][i];
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    int mult[m][m], prod=0;
    printf("Product of the two matrices:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<n; k++) {
                prod += matrix1[i][k] * matrix2[k][j];
            }
            mult[i][j] = prod;
            prod = 0;
            printf("%d ", mult[i][j]);
        }
        printf("\n");
    }
    int determinant = 0;
    printf("Determinant of the first matrix:\n");
    if(m == 2) {
        determinant = (matrix1[0][0] * matrix1[1][1]) - (matrix1[0][1] * matrix1[1][0]);
        printf("%d\n", determinant);
    } else {
        for(int i=0; i<m; i++) {
            int submatrix[m-1][m-1];
            for(int j=0; j<m-1; j++) {
                for(int k=0; k<m-1; k++) {
                    if(k < i) {
                        submatrix[j][k] = matrix1[j+1][k];
                    } else {
                        submatrix[j][k] = matrix1[j+1][k+1];
                    }
                }
            }
            if(i % 2 == 0) {
                determinant += matrix1[0][i] * getDeterminant(submatrix, m-1);
            } else {
                determinant -= matrix1[0][i] * getDeterminant(submatrix, m-1);
            }
        }
        printf("%d\n", determinant);
    }
    return 0;
}

int getDeterminant(int matrix[][10], int n) {
    int submatrix[n][n];
    int determinant = 0;
    if(n == 2) {
        determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        return determinant;
    } else {
        for(int i=0; i<n; i++) {
            int factor = 0;
            for(int j=0; j<n-1; j++) {
                for(int k=0; k<n-1; k++) {
                    if(k < i) {
                        submatrix[j][k] = matrix[j+1][k];
                    } else {
                        submatrix[j][k] = matrix[j+1][k+1];
                    }
                }
            }
            if(i % 2 == 0) {
                factor = matrix[0][i];
            } else {
                factor = -matrix[0][i];
            }
            determinant += factor * getDeterminant(submatrix, n-1);
        }
        return determinant;
    }
}