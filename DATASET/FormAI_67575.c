//FormAI DATASET v1.0 Category: Matrix operations ; Style: curious
#include<stdio.h>

//This program showcases matrix operations.

int main(){

    int m, n, i, j;

    //Get the size of the matrices from the user.
    printf("Enter the dimensions of the matrices:");
    scanf("%d %d", &m, &n);

    //Initialize the matrices
    int matrix1[m][n], matrix2[m][n], result[m][n];

    //Fill the matrices with user input
    printf("Enter the values for matrix 1:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the values for matrix 2:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    //Print the matrices
    printf("Matrix 1:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    //Add the matrices
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    //Print the result
    printf("Result after adding:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    //Subtract the matrices
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    //Print the result
    printf("Result after subtracting:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    //Transpose of matrices
    int transpose1[n][m], transpose2[n][m];

    //Transpose of Matrix1
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            transpose1[j][i] = matrix1[i][j];
        }
    }

    //Transpose of Matrix2
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            transpose2[j][i] = matrix2[i][j];
        }
    }

    //Print the transpose of matrices
    printf("Transpose of Matrix 1:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d ", transpose1[i][j]);
        }
        printf("\n");
    }

    printf("Transpose of Matrix 2:\n");
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d ", transpose2[i][j]);
        }
        printf("\n");
    }

    //Multiplication of matrices
    int matrix3[n][m];

    //Get the size of the new matrix from the user
    int p;
    printf("Enter the number of columns of matrix 2:");
    scanf("%d", &p);

    //Initialize the new matrix
    int k;
    for(i=0; i<m; i++){
        for(j=0; j<p; j++){
            matrix3[i][j] = 0;
        }
    }

    //Perform the multiplication
    for(i=0; i<m; i++){
        for(j=0; j<p; j++){
            for(k=0; k<n; k++){
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    //Print the result
    printf("Result after multiplying:\n");
    for(i=0; i<m; i++){
        for(j=0; j<p; j++){
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }

    return 0;
}