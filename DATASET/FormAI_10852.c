//FormAI DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int a[][3], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int c[2][2] = {0};

    printf("Matrix A:\n");
    printMatrix(a, 2, 3);
    printf("\nMatrix B:\n");
    printMatrix(b, 3, 2);

    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            c[i][j] = 0;
            for(int k=0; k<3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nMultiplication of Matrix A and B:\n");
    printMatrix(c, 2, 2);

    return 0;
}