//FormAI DATASET v1.0 Category: Matrix operations ; Style: introspective
#include<stdlib.h>
#include<stdio.h>

int main(){

    int rows, cols, i, j;
    int** matrix1;
    int** matrix2;
    int** result;

    //Get the matrix dimensions from user
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    //Allocate memory for the matrices
    matrix1 = (int**)malloc(rows * sizeof(int*));
    matrix2 = (int**)malloc(rows * sizeof(int*));
    result = (int**)malloc(rows * sizeof(int*));

    //Allocate memory for each row
    for(i = 0; i < rows; i++){
        matrix1[i] = (int*)malloc(cols * sizeof(int));
        matrix2[i] = (int*)malloc(cols * sizeof(int));
        result[i] = (int*)malloc(cols * sizeof(int));
    }

    //Get the values for the matrices
    printf("\nEnter the values for matrix 1:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter the values for matrix 2:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    //Perform matrix addition
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    //Print the result matrix
    printf("\nResultant Matrix is:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    //Deallocate the memory
    for(i = 0; i < rows; i++){
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}