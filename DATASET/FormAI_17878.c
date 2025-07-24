//FormAI DATASET v1.0 Category: Matrix operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

/* Function to print the matrix */
void printMatrix(int matrix[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to multiply two matrices */
void multiplyMatrix(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS], int result[ROWS][COLUMNS]){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLUMNS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main(){

    srand(time(NULL)); /* Seed the random number generator */
    int matrix1[ROWS][COLUMNS], matrix2[ROWS][COLUMNS];

    /* Generate the first matrix */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            matrix1[i][j] = rand() % 10;
        }
    }

    /* Generate the second matrix */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            matrix2[i][j] = rand() % 10;
        }
    }

    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2);

    /* Calculate the product matrix */
    int product_matrix[ROWS][COLUMNS];
    multiplyMatrix(matrix1, matrix2, product_matrix);

    printf("\nProduct Matrix:\n");
    printMatrix(product_matrix);

    return 0;
}