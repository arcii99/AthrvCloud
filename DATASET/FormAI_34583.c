//FormAI DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include<stdio.h>

// Program to perform matrix operations in futuristic style

int main() {
    int m, n, p, q;
    
    printf("Enter the dimensions of Matrix A: ");
    scanf("%d %d", &m, &n);
    
    printf("\nEnter the dimensions of Matrix B: ");
    scanf("%d %d", &p, &q);
    
    if(n != p) {
        printf("Dimension Mismatch!!! Cannot perform matrix multiplication");
        return 0;
    }
    
    int A[m][n], B[p][q], C[m][q];
    
    printf("\nEnter the elements of Matrix A:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("\nEnter the elements of Matrix B:\n");
    for(int i=0; i<p; i++) {
        for(int j=0; j<q; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    // Performing Matrix Multiplication
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<q; j++) {
            C[i][j] = 0;
            for(int k=0; k<n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    printf("\nThe Resultant Matrix C is:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<q; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
    
    // Performing Matrix Addition
    
    printf("\nPerforming Matrix Addition:\n");
    
    int D[m][n];
    
    printf("\nEnter the elements of Matrix D:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &D[i][j]);
            C[i][j] += D[i][j];
        }
    }
    
    printf("\nThe Resultant Matrix C after Addition is:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<q; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
    
    // Performing Matrix Transpose
    
    printf("\nPerforming Matrix Transpose:\n");
    
    int E[n][m];
    
    printf("\nThe Original Matrix A is:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d\t", A[i][j]);
            E[j][i] = A[i][j];
        }
        printf("\n");
    }
    
    printf("\nThe Transpose of Matrix A is:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("%d\t", E[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}