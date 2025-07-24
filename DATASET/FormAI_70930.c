//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>

int main()
{
    int matrix1[3][3] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};

    int matrix2[3][3] = {{9, 8, 7},
                         {6, 5, 4},
                         {3, 2, 1}};

    //displaying both matrices
    printf("Matrix 1: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix 2: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    //Matrix addition
    int sum[3][3];
    printf("Matrix Sum: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    //Matrix subtraction
    int difference[3][3];
    printf("Matrix Difference: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", difference[i][j]);
        }
        printf("\n");
    }

    //Matrix Multiplication
    int product[3][3];
    printf("Matrix Product: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            product[i][j] = 0;
            for(int k=0; k<3; k++){
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    //Matrix Transpose
    int transpose[3][3];
    printf("Matrix Transpose: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            transpose[j][i] = matrix1[i][j];
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}