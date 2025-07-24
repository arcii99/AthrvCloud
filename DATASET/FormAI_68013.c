//FormAI DATASET v1.0 Category: Matrix operations ; Style: Linus Torvalds
// Matrix operations program inspired by Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_MAX_SIZE 100

struct matrix {
    int rows, cols;
    float data[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE];
};

int matrix_equal(struct matrix a, struct matrix b);
struct matrix matrix_multiply(struct matrix a, struct matrix b);
void matrix_print(struct matrix mat);
struct matrix matrix_transpose(struct matrix mat);
struct matrix matrix_add(struct matrix a, struct matrix b);
struct matrix matrix_subtract(struct matrix a, struct matrix b);

int matrix_equal(struct matrix a, struct matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        return 0;
    }

    for (int i=0; i<a.rows; i++) {
        for (int j=0; j<a.cols; j++) {
            if (a.data[i][j] != b.data[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

struct matrix matrix_multiply(struct matrix a, struct matrix b) {
    struct matrix result;
    result.rows = a.rows;
    result.cols = b.cols;

    if (a.cols != b.rows) {
        printf("Error: matrices cannot be multiplied");
        exit(1);
    }

    for (int i=0; i<a.rows; i++) {
        for (int j=0; j<b.cols; j++) {
            float sum = 0.0;
            for (int k=0; k<a.cols; k++) {
                sum += a.data[i][k] * b.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

void matrix_print(struct matrix mat) {
    printf("[\n");
    for (int i=0; i<mat.rows; i++) {
        printf("  [ ");
        for (int j=0; j<mat.cols; j++) {
            printf("%f ", mat.data[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
}

struct matrix matrix_transpose(struct matrix mat) {
    struct matrix result;
    result.rows = mat.cols;
    result.cols = mat.rows;

    for (int i=0; i<mat.rows; i++) {
        for (int j=0; j<mat.cols; j++) {
            result.data[j][i] = mat.data[i][j];
        }
    }
    return result;
}

struct matrix matrix_add(struct matrix a, struct matrix b) {
    struct matrix result;
    result.rows = a.rows;
    result.cols = a.cols;

    if (!matrix_equal(a, b)) {
        printf("Error: matrices must be of the same size for addition");
        exit(1);
    }

    for (int i=0; i<a.rows; i++) {
        for (int j=0; j<a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

struct matrix matrix_subtract(struct matrix a, struct matrix b) {
    struct matrix result;
    result.rows = a.rows;
    result.cols = a.cols;

    if (!matrix_equal(a, b)) {
        printf("Error: matrices must be of the same size for subtraction");
        exit(1);
    }

    for (int i=0; i<a.rows; i++) {
        for (int j=0; j<a.cols; j++) {
            result.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    return result;
}

int main() {
    struct matrix A, B, C;

    // Define matrix A
    A.rows = 2;
    A.cols = 3;
    A.data[0][0] = 1.0;
    A.data[0][1] = 2.0;
    A.data[0][2] = 3.0;
    A.data[1][0] = 4.0;
    A.data[1][1] = 5.0;
    A.data[1][2] = 6.0;

    // Define matrix B
    B.rows = 3;
    B.cols = 2;
    B.data[0][0] = 7.0;
    B.data[0][1] = 8.0;
    B.data[1][0] = 9.0;
    B.data[1][1] = 10.0;
    B.data[2][0] = 11.0;
    B.data[2][1] = 12.0;

    printf("Matrix A:\n");
    matrix_print(A);

    printf("Matrix B:\n");
    matrix_print(B);

    // Multiply A and B
    printf("A x B:\n");
    C = matrix_multiply(A, B);
    matrix_print(C);

    // Transpose A
    printf("Transpose of A:\n");
    C = matrix_transpose(A);
    matrix_print(C);

    // Add A and B
    printf("A + B:\n");
    C = matrix_add(A, B);
    matrix_print(C);

    // Subtract A and B
    printf("A - B:\n");
    C = matrix_subtract(A, B);
    matrix_print(C);

    return 0;
}