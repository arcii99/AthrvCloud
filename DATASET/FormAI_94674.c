//FormAI DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>

void matrix_addition(int row, int col, int a[row][col], int b[row][col]) {
    int c[row][col];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Matrix addition:\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void matrix_subtraction(int row, int col, int a[row][col], int b[row][col]) {
    int c[row][col];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("Matrix subtraction:\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void matrix_multiplication(int row, int col1, int col2, int a[row][col1], int b[col1][col2]) {
    int c[row][col2];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col2; j++) {
            c[i][j] = 0;
            for(int k = 0; k < col1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Matrix multiplication:\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row, col1, col2, choice;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &col1);
    int a[row][col1];
    printf("Enter matrix 1:\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &col2);
    int b[col1][col2];
    printf("Enter matrix 2:\n");
    for(int i = 0; i < col1; i++) {
        for(int j = 0; j < col2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    printf("Choose matrix operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            if(col1 != col2) {
                printf("Invalid matrix dimensions for addition");
                break;
            }
            matrix_addition(row, col1, a, b);
            break;
        case 2:
            if(col1 != col2) {
                printf("Invalid matrix dimensions for subtraction");
                break;
            }
            matrix_subtraction(row, col1, a, b);
            break;
        case 3:
            if(col1 != row) {
                printf("Invalid matrix dimensions for multiplication");
                break;
            }
            matrix_multiplication(row, col1, col2, a, b);
            break;
        default:
            printf("Invalid choice");
    }
    return 0;
}