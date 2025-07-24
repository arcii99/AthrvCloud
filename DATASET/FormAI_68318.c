//FormAI DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows, columns;   // declare variables for matrix dimensions
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &columns);

    // allocate memory for matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++){
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }

    // populate matrix with random values
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            matrix[i][j] = rand() % 10;   // generate random integer between 0 and 9
        }
    }

    // print original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // transpose matrix
    int **transpose = (int **)malloc(columns * sizeof(int *));
    for (int i = 0; i < columns; i++){
        transpose[i] = (int *)malloc(rows * sizeof(int));
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            transpose[j][i] = matrix[i][j];
        }
    }

    // print transposed matrix
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < columns; i++){
        for (int j = 0; j < rows; j++){
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // multiply matrix by scalar
    int scalar;
    printf("\nEnter a scalar to multiply the matrix by: ");
    scanf("%d", &scalar);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            matrix[i][j] *= scalar;
        }
    }

    // print multiplied matrix
    printf("\nMultiplied Matrix:\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // free allocated memory
    for (int i = 0; i < rows; i++){
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < columns; i++){
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}