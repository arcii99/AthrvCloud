//FormAI DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            result[i][j] = 0;
            for(int k=0; k<ROWS; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main(){
    int matrix1[ROWS][COLS] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    int matrix2[ROWS][COLS] = { { 9, 8, 7 }, { 6, 5, 4 }, { 3, 2, 1 } };
    int result[ROWS][COLS];

    printf("Matrix 1:\n");
    printMatrix(matrix1);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2);

    printf("\nAddition Result:\n");
    addMatrix(matrix1, matrix2, result);
    printMatrix(result);

    printf("\nSubtraction Result:\n");
    subtractMatrix(matrix1, matrix2, result);
    printMatrix(result);

    printf("\nMultiplication Result:\n");
    multiplyMatrix(matrix1, matrix2, result);
    printMatrix(result);

    return 0;
}