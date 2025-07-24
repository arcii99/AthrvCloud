//FormAI DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void displayMatrix(int matrix[ROWS][COLS]) {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int resultMatrix[ROWS][COLS];
    printf("Adding matrices...\n");
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    displayMatrix(resultMatrix);    
}

void subtractMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int resultMatrix[ROWS][COLS];
    printf("Subtracting matrices...\n");
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    displayMatrix(resultMatrix);    
}

void multiplyMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]) {
    int resultMatrix[ROWS][COLS];
    printf("Multiplying matrices...\n");
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            resultMatrix[i][j] = 0;
            for (int k=0; k<COLS; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    displayMatrix(resultMatrix);
}

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    printf("Matrix 1:\n");
    displayMatrix(matrix1);
    printf("Matrix 2:\n");
    displayMatrix(matrix2);
    
    addMatrices(matrix1, matrix2);
    printf("\n");
    subtractMatrices(matrix1, matrix2);
    printf("\n");
    multiplyMatrices(matrix1, matrix2);
    
    return 0;
}