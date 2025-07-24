//FormAI DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    int rows = 3;
    int cols = 3;

    printf("Let's perform some matrix operations!\n");

    // generate first matrix
    int a[rows][cols];
    printf("\nFirst Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i][j] = rand() % 10; // generate random integer between 0 and 9
            printf("%d ", a[i][j]); // print value
        }
        printf("\n"); // move to next row
    }

    // generate second matrix
    int b[rows][cols];
    printf("\nSecond Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            b[i][j] = rand() % 10; // generate random integer between 0 and 9
            printf("%d ", b[i][j]); // print value
        }
        printf("\n"); // move to next row
    }

    // addition
    int c[rows][cols];
    printf("\nAddition of matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // subtraction
    int d[rows][cols];
    printf("\nSubtraction of matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            d[i][j] = a[i][j] - b[i][j];
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    // multiplication
    int e[rows][cols];
    printf("\nMultiplication of matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            e[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                e[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", e[i][j]);
        }
        printf("\n");
    }

    printf("\nThank you for performing matrix operations with me!");

    return 0;
}