//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>

void printMatrix(int matrix[3][3]) {
    printf("=======The Matrix=======\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("========================\n");
}

void multiplyMatrix(int matrix1[3][3], int matrix2[3][3], int result[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{3, 2, 1}, {6, 5, 4}, {9, 8, 7}};
    int result[3][3];

    printf("Welcome to the Matrix Operations Program!\n");

    printf("\nFirst, let's see the original matrices:\n");
    printMatrix(matrix1);
    printMatrix(matrix2);

    printf("\nNow, let's multiply them:");
    multiplyMatrix(matrix1, matrix2, result);
    printf("\nThe result is:\n");
    printMatrix(result);

    printf("\nThank you for using the Matrix Operations Program! Have a happy day!\n");

    return 0;
}