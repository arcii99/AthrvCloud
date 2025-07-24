//FormAI DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Matrix Operation Functions
void add_matrices(int m, int n, int A[m][n], int B[m][n], int C[m][n]){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract_matrices(int m, int n, int A[m][n], int B[m][n], int C[m][n]){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void scalar_multiplication(int m, int n, int k, int A[m][n], int C[m][n]){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            C[i][j] = k * A[i][j];
        }
    }
}

void transpose_matrix(int m, int n, int A[m][n], int C[n][m]){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            C[j][i] = A[i][j];
        }
    }
}

void matrix_multiplication(int m, int n, int p, int A[m][n], int B[n][p], int C[m][p]){
    int i, j, k;
    for(i=0; i<m; i++){
        for(j=0; j<p; j++){
            C[i][j] = 0;
            for(k=0; k<n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Main Function
int main(){
    // Variables for Matrix Operation Input
    int m, n, p, k;
    int i, j;
    
    // Get Matrix Operation Input
    printf("Enter the number of rows in matrix A: ");
    scanf("%d", &m);
    printf("Enter the number of columns in matrix A: ");
    scanf("%d", &n);
    int A[m][n];
    printf("Enter the elements of matrix A:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("Enter the number of rows in matrix B: ");
    scanf("%d", &p);
    printf("Enter the number of columns in matrix B: ");
    scanf("%d", &n);
    int B[p][n];
    printf("Enter the elements of matrix B:\n");
    for(i=0; i<p; i++){
        for(j=0; j<n; j++){
            scanf("%d", &B[i][j]);
        }
    }

    // Perform Matrix Operations
    int result[m][n];
    int result2[p][n];
    int result3[m][n];
    int result4[n][m];
    int result5[m][p];
    
    add_matrices(m, n, A, B, result);
    subtract_matrices(m, n, A, B, result2);
    printf("\nMatrix A + Matrix B:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix A - Matrix B:\n");
    for(i=0; i<p; i++){
        for(j=0; j<n; j++){
            printf("%d ", result2[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the scalar value for multiplication: ");
    scanf("%d", &k);
    scalar_multiplication(m, n, k, A, result3);
    printf("\nScalar Multiplication of Matrix A with %d:\n", k);
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", result3[i][j]);
        }
        printf("\n");
    }

    transpose_matrix(m, n, A, result4);
    printf("\nTransposed Matrix of Matrix A:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d ", result4[i][j]);
        }
        printf("\n");
    }

    matrix_multiplication(m, n, p, A, B, result5);
    printf("\nMatrix A * Matrix B:\n");
    for(i=0; i<m; i++){
        for(j=0; j<p; j++){
            printf("%d ", result5[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}