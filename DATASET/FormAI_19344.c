//FormAI DATASET v1.0 Category: Matrix operations ; Style: curious
#include <stdio.h>

int main() {
    printf("Hello curious coder!\n");

    // Matrix initialization
    int rows = 3;
    int cols = 3;
    int matrix[rows][cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = i*j;
        }
    }

    printf("Original matrix:\n");
    // Displaying original matrix
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transposing matrix
    printf("\nTransposed matrix:\n");
    int transpose[cols][rows];
    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            transpose[i][j] = matrix[j][i];
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Multiplying two matrices
    printf("\nMultiplying two matrices:\n");
    int matrix1[3][2] = {{1,2}, {3,4}, {5,6}};
    int matrix2[2][3] = {{1,2,3}, {4,5,6}};
    int product[3][3];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            product[i][j] = 0;
            for(int k=0; k<2; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    // Finding determinant of matrix
    int determinant = matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[2][1]*matrix[1][2]) - matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0]) + matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]);
    printf("\nDeterminant of matrix: %d\n", determinant);

    printf("\nThanks for being curious and exploring matrix operations!\n");

    return 0;
}