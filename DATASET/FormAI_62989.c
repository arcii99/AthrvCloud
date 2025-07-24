//FormAI DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>

#define ROWS 3
#define COLUMNS 3

void printMatrix(int matrix[ROWS][COLUMNS]){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS]){
    int result[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("The result of addition is:\n");
    printMatrix(result);
}

void subtractMatrix(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS]){
    int result[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printf("The result of subtraction is:\n");
    printMatrix(result);
}

void multiplyMatrix(int matrix1[ROWS][COLUMNS], int matrix2[ROWS][COLUMNS]){
    int result[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < ROWS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("The result of multiplication is:\n");
    printMatrix(result);
}

int main(){
    int matrix1[ROWS][COLUMNS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLUMNS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("Matrix 2:\n");
    printMatrix(matrix2);

    addMatrix(matrix1, matrix2);
    subtractMatrix(matrix1, matrix2);
    multiplyMatrix(matrix1, matrix2);

    return 0;
}