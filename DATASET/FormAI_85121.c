//FormAI DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>

void printMatrix(int matrix[][3], int size) {
    printf("\n");
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int matrix1[][3], int matrix2[][3], int resultant[][3], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            int sum = 0;
            for(int k=0; k<size; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            resultant[i][j] = sum;
        }
    }
}

int main()
{
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int resultant[3][3] = {0};
    int size = 3;
    
    printf("Matrix 1:\n");
    printMatrix(matrix1, size);
    printf("Matrix 2:\n");
    printMatrix(matrix2, size);
    
    multiplyMatrix(matrix1, matrix2, resultant, size);
    
    printf("Resultant Matrix:\n");
    printMatrix(resultant, size);

    return 0;
}