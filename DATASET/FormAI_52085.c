//FormAI DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Variables initialization
    int n, m, i, j, option, scalar, isSquare;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of columns: ");
    scanf("%d", &m);

    // Matrix initialization
    int mat[n][m];
    printf("\nEnter the elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Display matrix
    printf("\nInput Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    // Check if the matrix is a square matrix
    isSquare = (n == m ? 1 : 0);

    // Menu for matrix operations
    do {
        printf("\nMatrix Operations:\n1. Scalar Multiplication\n2. Matrix Addition\n3. Matrix Subtraction\n4. Matrix Multiplication\n5. Transpose of a Matrix\n6. Exit\nEnter option: ");
        scanf("%d", &option);

        // Switch case for various matrix operations
        switch(option) {

            // Scalar multiplication
            case 1:
            printf("\nEnter scalar value to be multiplied: ");
            scanf("%d", &scalar);
            for(i = 0; i < n; i++) {
                for(j = 0; j < m; j++) {
                    mat[i][j] *= scalar;
                }
            }
            printf("\nOutput Matrix:\n");
            for(i = 0; i < n; i++) {
                for(j = 0; j < m; j++) {
                    printf("%d\t", mat[i][j]);
                }
                printf("\n");
            }
            break;

            // Matrix addition
            case 2:
            if(isSquare) {
                int a[n][n];
                printf("\nEnter another square matrix of order %d:\n", n);
                for(i = 0; i < n; i++) {
                    for(j = 0; j < n; j++) {
                        scanf("%d", &a[i][j]);
                    }
                }
                printf("\nOutput Matrix:\n");
                for(i = 0; i < n; i++) {
                    for(j = 0; j < n; j++) {
                        printf("%d\t", (mat[i][j] + a[i][j]));
                    }
                    printf("\n");
                }
                break;
            }
            else {
                printf("\nMatrix is not a square matrix! Cannot perform addition.\n");
                break;
            }

            // Matrix subtraction
            case 3:
            if(isSquare) {
                int a[n][n];
                printf("\nEnter another square matrix of order %d:\n", n);
                for(i = 0; i < n; i++) {
                    for(j = 0; j < n; j++) {
                        scanf("%d", &a[i][j]);
                    }
                }
                printf("\nOutput Matrix:\n");
                for(i = 0; i < n; i++) {
                    for(j = 0; j < n; j++) {
                        printf("%d\t", (mat[i][j] - a[i][j]));
                    }
                    printf("\n");
                }
                break;
            }
            else {
                printf("\nMatrix is not a square matrix! Cannot perform subtraction.\n");
                break;
            }

            // Matrix multiplication
            case 4:
            if(isSquare) {
                int a[n][n], result[n][n], k;
                printf("\nEnter another square matrix of order %d:\n", n);
                for(i = 0; i < n; i++) {
                    for(j = 0; j < n; j++) {
                        scanf("%d", &a[i][j]);
                    }
                }
                // Multiplying matrices
                for(i = 0; i < n; i++) {
                    for(j = 0; j < n; j++) {
                        result[i][j] = 0;
                        for(k = 0; k < n; k++) {
                            result[i][j] += (mat[i][k] * a[k][j]);
                        }
                    }
                }
                printf("\nOutput Matrix:\n");
                for(i = 0; i < n; i++) {
                    for(j = 0; j < n; j++) {
                        printf("%d\t", result[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            else {
                printf("\nMatrix is not a square matrix! Cannot perform multiplication.\n");
                break;
            }

            // Transpose of a matrix
            case 5:
            if(isSquare) {
                printf("\nOutput Matrix:\n");
                for(i = 0; i < n; i++) {
                    for(j = 0; j < n; j++) {
                        printf("%d\t", mat[j][i]);
                    }
                    printf("\n");
                }
                break;
            }
            else {
                int transpose[m][n];
                printf("\nOutput Matrix:\n");
                for(i = 0; i < m; i++) {
                    for(j = 0; j < n; j++) {
                        transpose[i][j] = mat[j][i];
                        printf("%d\t", transpose[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            // Exit
            case 6:
            printf("\nExiting program...\n");
            exit(0);

            // Invalid option
            default:
            printf("\nInvalid option! Please try again.\n");

        }
    } while(option != 6);

    return 0;
}