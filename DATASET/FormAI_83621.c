//FormAI DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MATRIX_SIZE 5

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int i, j;

    // Populating matrix with random numbers between 1 and 10
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }

    // Printing the matrix in a puzzling way
    printf("The original matrix is:\n");
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Finding the sum of all elements of the matrix
    int sum = 0;
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            sum += matrix[i][j];
        }
    }

    // Printing the sum of all elements of the matrix in a puzzling way
    printf("\nThe sum of all elements of the matrix is: ");
    for (i = 0; i < sum; i++) {
        printf("*");
    }
    printf("\n");

    // Transposing the matrix
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = i + 1; j < MATRIX_SIZE; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Printing the transposed matrix in a puzzling way
    printf("\nThe transposed matrix is:\n");
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculating the determinant of the matrix
    int determinant = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - 
                      matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + 
                      matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    // Printing the determinant of the matrix in a puzzling way
    printf("\nThe determinant of the matrix is: ");
    for (i = 0; i < determinant; i++) {
        printf("#");
    }
    printf("\n");

    return 0;
}