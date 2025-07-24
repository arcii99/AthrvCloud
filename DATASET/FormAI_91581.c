//FormAI DATASET v1.0 Category: Data mining ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 3
#define COL_SIZE 3

void printMatrix(int content[][COL_SIZE], int rowSize, int colSize) {
    int i, j;
    for (i = 0; i < rowSize; i++) {
        for (j = 0; j < colSize; j++) {
            printf("%d ", content[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int firstContent[][COL_SIZE], int secondContent[][COL_SIZE], int resultContent[][COL_SIZE]) {
    int i, j, k;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            resultContent[i][j] = 0;
            for (k = 0; k < COL_SIZE; k++) {
                resultContent[i][j] += firstContent[i][k] * secondContent[k][j];
            }
        }
    }
}

int main() {
    int firstMatrixContent[ROW_SIZE][COL_SIZE] = { {1, 2, 3},
                                                    {4, 5, 6},
                                                    {7, 8, 9} };
 
    int secondMatrixContent[ROW_SIZE][COL_SIZE] = { {9, 8, 7},
                                                     {6, 5, 4},
                                                     {3, 2, 1} };

    int resultMatrixContent[ROW_SIZE][COL_SIZE];

    multiplyMatrix(firstMatrixContent, secondMatrixContent, resultMatrixContent);

    printf("First Matrix: \n");
    printMatrix(firstMatrixContent, ROW_SIZE, COL_SIZE);

    printf("Second Matrix: \n");
    printMatrix(secondMatrixContent, ROW_SIZE, COL_SIZE);

    printf("Result Matrix: \n");
    printMatrix(resultMatrixContent, ROW_SIZE, COL_SIZE);

    return 0;
}