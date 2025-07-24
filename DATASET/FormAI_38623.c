//FormAI DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>

#define ROW 3
#define COL 3

void displayMatrix(int matrix[ROW][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrix1[ROW][COL], int matrix2[ROW][COL], int resultMatrix[ROW][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void transposeMatrix(int matrix[ROW][COL], int transposedMatrix[COL][ROW]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix1[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROW][COL] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int resultMatrix[ROW][COL];
    int transposedMatrix[COL][ROW];
    
    // Display the initial matrices
    printf("Matrix 1:\n");
    displayMatrix(matrix1);
    
    printf("\nMatrix 2:\n");
    displayMatrix(matrix2);
    
    printf("\n");
    
    // Add the matrices
    addMatrix(matrix1, matrix2, resultMatrix);
    printf("Matrix 1 + Matrix 2:\n");
    displayMatrix(resultMatrix);
    
    printf("\n");
    
    // Transpose Matrix 1
    transposeMatrix(matrix1, transposedMatrix);
    printf("Transposed Matrix 1:\n");
    displayMatrix(transposedMatrix);
    
    return 0;
}