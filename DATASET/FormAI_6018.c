//FormAI DATASET v1.0 Category: Matrix operations ; Style: automated
#include<stdio.h>
#include<stdlib.h>

void add(int **matrix1, int **matrix2, int **result, int row, int col) {
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtract(int **matrix1, int **matrix2, int **result, int row, int col) {
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiply(int **matrix1, int **matrix2, int **result, int row1, int col1, int col2) {
    for(int i=0;i<row1;i++) {
        for(int j=0;j<col2;j++) {
            result[i][j] = 0;
            for(int k=0;k<col1;k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void display(int **matrix, int row, int col) {
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row1, col1, row2, col2;

    printf("Enter the number of rows and columns for first matrix\n");
    scanf("%d %d", &row1, &col1);
    printf("Enter the number of rows and columns for second matrix\n");
    scanf("%d %d", &row2, &col2);

    if(col1 != row2) {
        printf("The matrices cannot be multiplied\n");
        exit(0);
    }

    int **matrix1 = (int **)malloc(row1 * sizeof(int *));
    for(int i=0;i<row1;i++) {
        matrix1[i] = (int *)malloc(col1 * sizeof(int));
    }

    int **matrix2 = (int **)malloc(row2 * sizeof(int *));
    for(int i=0;i<row2;i++) {
        matrix2[i] = (int *)malloc(col2 * sizeof(int));
    }

    int **result = (int **)malloc(row1 * sizeof(int *));
    for(int i=0;i<row1;i++) {
        result[i] = (int *)malloc(col2 * sizeof(int));
    }

    printf("Enter the values for first matrix\n");
    for(int i=0;i<row1;i++) {
        for(int j=0;j<col1;j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the values for second matrix\n");
    for(int i=0;i<row2;i++) {
        for(int j=0;j<col2;j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("The first matrix is\n");
    display(matrix1, row1, col1);

    printf("The second matrix is\n");
    display(matrix2, row2, col2);

    printf("The sum of the matrices is\n");
    add(matrix1, matrix2, result, row1, col1);
    display(result, row1, col1);

    printf("The difference of the matrices is\n");
    subtract(matrix1, matrix2, result, row1, col1);
    display(result, row1, col1);

    printf("The product of the matrices is\n");
    multiply(matrix1, matrix2, result, row1, col1, col2);
    display(result, row1, col2);

    for(int i=0;i<row1;i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for(int i=0;i<row2;i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for(int i=0;i<row1;i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}