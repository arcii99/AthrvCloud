//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include<stdio.h>
#include<stdlib.h>

int main() {
    int rows, cols, option;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int *matrix = (int*)malloc(rows * cols * sizeof(int));
    int *result = (int*)malloc(rows * cols * sizeof(int));

    printf("Enter the matrix:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrix[i*cols+j]);
        }
    }

    printf("Choose an operation to perform:\n");
    printf("1. Transpose\n");
    printf("2. Add\n");
    printf("3. Subtract\n");
    printf("4. Multiply by scalar\n");
    printf("5. Multiply by Matrix\n");
    printf("Enter option number: ");
    scanf("%d", &option);

    switch(option) {
        case 1: // Transpose
            for(int i=0; i<cols; i++) {
                for(int j=0; j<rows; j++) {
                    result[i*rows+j] = matrix[j*cols+i];
                }
            }
            printf("The transpose of the matrix is:\n");
            for(int i=0; i<cols; i++) {
                for(int j=0; j<rows; j++) {
                    printf("%d ", result[i*rows+j]);
                }
                printf("\n");
            }
            break;
        case 2: // Add
            printf("Enter the second matrix:\n");
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    scanf("%d", &result[i*cols+j]);
                }
            }
            printf("The sum of the two matrices is:\n");
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    printf("%d ", matrix[i*cols+j] + result[i*cols+j]);
                }
                printf("\n");
            }
            break;
        case 3: // Subtract
            printf("Enter the second matrix:\n");
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    scanf("%d", &result[i*cols+j]);
                }
            }
            printf("The result of subtraction is:\n");
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    printf("%d ", matrix[i*cols+j] - result[i*cols+j]);
                }
                printf("\n");
            }
            break;
        case 4: // Multiply by scalar
            int scalar;
            printf("Enter scalar value: ");
            scanf("%d", &scalar);
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    result[i*cols+j] = matrix[i*cols+j] * scalar;
                }
            }
            printf("The result of scalar multiplication is:\n");
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    printf("%d ", result[i*cols+j]);
                }
                printf("\n");
            }
            break;
        case 5: // Multiply by matrix
            int mRows, mCols;
            printf("Enter the number of rows and columns for the second matrix: ");
            scanf("%d %d", &mRows, &mCols);
            if(cols != mRows) {
                printf("Invalid dimensions for multiplication\n");
                break;
            }
            int *matrix2 = (int*)malloc(mRows * mCols * sizeof(int));
            printf("Enter the second matrix:\n");
            for(int i=0; i<mRows; i++) {
                for(int j=0; j<mCols; j++) {
                    scanf("%d", &matrix2[i*mCols+j]);
                }
            }
            for(int i=0; i<rows; i++) {
                for(int j=0; j<mCols; j++) {
                    int sum = 0;
                    for(int k=0; k<cols; k++) {
                        sum += matrix[i*cols+k] * matrix2[k*mCols+j];
                    }
                    result[i*mCols+j] = sum;
                }
            }
            printf("The result of multiplication is:\n");
            for(int i=0; i<rows; i++) {
                for(int j=0; j<mCols; j++) {
                    printf("%d ", result[i*mCols+j]);
                }
                printf("\n");
            }
            free(matrix2);
            break;
        default:
            printf("Invalid option\n");
    }

    free(matrix);
    free(result);
    return 0;
}