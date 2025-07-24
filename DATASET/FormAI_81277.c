//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void matrix_multiplication(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int result[SIZE][SIZE]) {
    int sum = 0;
    
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            for(int k = 0; k < SIZE; k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
    }
}

int main() {
    int mat1[SIZE][SIZE], mat2[SIZE][SIZE], result[SIZE][SIZE];

    // populate matrices with random numbers
    srand(time(NULL));

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            mat1[i][j] = rand() % 10;
            mat2[i][j] = rand() % 10;
        }
    }

    // perform matrix multiplication
    matrix_multiplication(mat1, mat2, result);

    // print result
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}