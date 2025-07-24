//FormAI DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>

int main() {
    printf("Woo-hoo! It's time to perform some awesome Matrix operations!\n");

    // Initializing two matrices
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};

    // Displaying matrices
    printf("\nMatrix 1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    // Adding two matrices
    int result[3][3];
    printf("\nMatrix Addition:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Multiplying two matrices
    int product[3][3];
    printf("\nMatrix Multiplication:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            product[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    printf("\nIsn't it awesome! We have successfully performed Matrix operations!\n");

    return 0;
}