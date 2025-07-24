//FormAI DATASET v1.0 Category: Matrix operations ; Style: Alan Touring
#include<stdio.h>
#define ROW 3
#define COL 3

void dispMatrix(int matrix[ROW][COL]);
void sumMatrix(int matrix1[ROW][COL], int matrix2[ROW][COL], int result[ROW][COL]);
void subMatrix(int matrix1[ROW][COL], int matrix2[ROW][COL], int result[ROW][COL]);
void multMatrix(int matrix1[ROW][COL], int matrix2[ROW][COL], int result[ROW][COL]);

int main() {
    int matrix1[ROW][COL] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int matrix2[ROW][COL] = { {9,8,7}, {6,5,4}, {3,2,1} };
    int result[ROW][COL];

    printf("Matrix 1:\n");
    dispMatrix(matrix1);

    printf("\nMatrix 2:\n");
    dispMatrix(matrix2);

    printf("\nMatrix 1 + Matrix 2:\n");
    sumMatrix(matrix1, matrix2, result);
    dispMatrix(result);

    printf("\nMatrix 1 - Matrix 2:\n");
    subMatrix(matrix1, matrix2, result);
    dispMatrix(result);

    printf("\nMatrix 1 * Matrix 2:\n");
    multMatrix(matrix1, matrix2, result);
    dispMatrix(result);

    return 0;
}

void dispMatrix(int matrix[ROW][COL]) {
    int row, col;

    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

void sumMatrix(int matrix1[ROW][COL], int matrix2[ROW][COL], int result[ROW][COL]) {
    int row, col;

    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            result[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }
}

void subMatrix(int matrix1[ROW][COL], int matrix2[ROW][COL], int result[ROW][COL]) {
    int row, col;

    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            result[row][col] = matrix1[row][col] - matrix2[row][col];
        }
    }
}

void multMatrix(int matrix1[ROW][COL], int matrix2[ROW][COL], int result[ROW][COL]) {
    int row, col, k;

    for (row = 0; row < ROW; row++) {
        for (col = 0; col < COL; col++) {
            result[row][col] = 0;

            for (k = 0; k < COL; k++) {
                result[row][col] += matrix1[row][k] * matrix2[k][col];
            }
        }
    }
}