//FormAI DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} Matrix;

void print_matrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *add_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: matrices must have the same dimensions\n");
        return NULL;
    }

    Matrix *result = malloc(sizeof(Matrix));
    result->rows = a->rows;
    result->cols = a->cols;
    result->data = malloc(result->rows * sizeof(int *));
    for (int i = 0; i < result->rows; i++) {
        result->data[i] = malloc(result->cols * sizeof(int));
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return result;
}

Matrix *multiply_matrices(Matrix *a, Matrix *b) {
    if (a->cols != b->rows) {
        printf("Error: number of columns in first matrix must match number of rows in second matrix\n");
        return NULL;
    }

    Matrix *result = malloc(sizeof(Matrix));
    result->rows = a->rows;
    result->cols = b->cols;
    result->data = malloc(result->rows * sizeof(int *));
    for (int i = 0; i < result->rows; i++) {
        result->data[i] = malloc(result->cols * sizeof(int));
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return result;
}

int main() {
    printf("Welcome to the Matrix Operations Program - Cyberpunk Edition\n");
    printf("Enter the number of rows for matrix A: ");
    int rows_a;
    scanf("%d", &rows_a);
    printf("Enter the number of columns for matrix A: ");
    int cols_a;
    scanf("%d", &cols_a);

    Matrix *a = malloc(sizeof(Matrix));
    a->rows = rows_a;
    a->cols = cols_a;
    a->data = malloc(a->rows * sizeof(int *));
    printf("Enter the values for matrix A (separate each element by a space):\n");
    for (int i = 0; i < a->rows; i++) {
        a->data[i] = malloc(a->cols * sizeof(int));
        for (int j = 0; j < a->cols; j++) {
            scanf("%d", &(a->data[i][j]));
        }
    }

    printf("Enter the number of rows for matrix B: ");
    int rows_b;
    scanf("%d", &rows_b);
    printf("Enter the number of columns for matrix B: ");
    int cols_b;
    scanf("%d", &cols_b);

    Matrix *b = malloc(sizeof(Matrix));
    b->rows = rows_b;
    b->cols = cols_b;
    b->data = malloc(b->rows * sizeof(int *));
    printf("Enter the values for matrix B (separate each element by a space):\n");
    for (int i = 0; i < b->rows; i++) {
        b->data[i] = malloc(b->cols * sizeof(int));
        for (int j = 0; j < b->cols; j++) {
            scanf("%d", &(b->data[i][j]));
        }
    }

    printf("What operation would you like to perform?\n");
    printf("1. Add matrices\n");
    printf("2. Multiply matrices\n");
    int option;
    scanf("%d", &option);

    Matrix *result;
    switch (option) {
        case 1:
            result = add_matrices(a, b);
            if (result != NULL) {
                printf("The result is:\n");
                print_matrix(result);
                for (int i = 0; i < result->rows; i++) {
                    free(result->data[i]);
                }
                free(result->data);
                free(result);
            }
            break;
        case 2:
            result = multiply_matrices(a, b);
            if (result != NULL) {
                printf("The result is:\n");
                print_matrix(result);
                for (int i = 0; i < result->rows; i++) {
                    free(result->data[i]);
                }
                free(result->data);
                free(result);
            }
            break;
        default:
            printf("Invalid option selected\n");
            break;
    }

    for (int i = 0; i < a->rows; i++) {
        free(a->data[i]);
    }
    free(a->data);
    free(a);

    for (int i = 0; i < b->rows; i++) {
        free(b->data[i]);
    }
    free(b->data);
    free(b);

    return 0;
}