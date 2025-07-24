//FormAI DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j, opt;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *)); // allocating memory dynamically
    for (i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    printf("Enter the elements of the matrix: \n");

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    printf("The matrix entered by the user is: \n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("What operation do you want to perform?\n");
    printf("1. Transpose\n2. Multiply by a constant\n3. Add two matrices\n");
    scanf("%d", &opt);

    int **res_matrix = (int **)malloc(rows * sizeof(int *)); // creating a result matrix
    for (i = 0; i < rows; i++)
        res_matrix[i] = (int *)malloc(cols * sizeof(int));

    switch (opt) {
        case 1: // transpose
            printf("The transposed matrix is: \n");

            for (i = 0; i < cols; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%d ", matrix[j][i]);
                }
                printf("\n");
            }
            break;

        case 2: // multiply by a constant
            int constant;
            printf("Enter the constant value: ");
            scanf("%d", &constant);

            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    res_matrix[i][j] = constant * matrix[i][j];
                }
            }

            printf("The resultant matrix is: \n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%d ", res_matrix[i][j]);
                }
                printf("\n");
            }
            break;

        case 3: // add two matrices
            int **matrix2 = (int **)malloc(rows * sizeof(int *));
            for (i = 0; i < rows; i++)
                matrix2[i] = (int *)malloc(cols * sizeof(int));

            printf("Enter the elements of the second matrix: \n");
            for (i = 0; i < rows; i++)
                for (j = 0; j < cols; j++)
                    scanf("%d", &matrix2[i][j]);

            printf("The second matrix entered by the user is: \n");

            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%d ", matrix2[i][j]);
                }
                printf("\n");
            }

            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    res_matrix[i][j] = matrix[i][j] + matrix2[i][j];
                }
            }

            printf("The sum of the two matrices is: \n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%d ", res_matrix[i][j]);
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}