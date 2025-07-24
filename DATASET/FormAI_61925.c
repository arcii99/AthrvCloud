//FormAI DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 5

int count = 0;

void print_matrix(int matrix[N][M]) {
    printf("Matrix:\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fill_matrix(int matrix[N][M]) {
    srand(time(NULL));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void multiply_by_scalar(int matrix[N][M], int scalar) {
    printf("Multiplying matrix by scalar...\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            matrix[i][j] *= scalar;
        }
    }
    printf("Done.\n\n");
}

void add_matrices(int matrix1[N][M], int matrix2[N][M], int result[N][M]) {
    printf("Adding matrices...\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Done.\n\n");
}

void transpose_matrix(int matrix[N][M]) {
    printf("Transposing matrix...\n");
    for (int i=0; i<N; i++) {
        for (int j=i; j<M; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
            count++;
        }
    }
    printf("Done.\n\n");
}

void puzzle() {
    int matrix1[N][M], matrix2[N][M], result[N][M];
    printf("Welcome to the matrix operations puzzle!\n\n");
    printf("You have been given two matrices of size %d x %d.\n\n", N, M);
    printf("Matrix 1:\n");
    fill_matrix(matrix1);
    print_matrix(matrix1);
    printf("Matrix 2:\n");
    fill_matrix(matrix2);
    print_matrix(matrix2);

    multiply_by_scalar(matrix1, 2);
    add_matrices(matrix1, matrix2, result);
    transpose_matrix(result);

    printf("The final result after all operations is:\n");
    print_matrix(result);

    printf("You have completed the puzzle in %d steps.\n", count);
    printf("Congratulations!\n\n");
}

int main() {
    puzzle();
    return 0;
}