//FormAI DATASET v1.0 Category: Matrix operations ; Style: Sherlock Holmes
#include <stdio.h>

//function to print a matrix
void printMatrix(int matrix[][3], int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//function to perform matrix multiplication
void matrixMultiply(int matrix1[][3], int matrix2[][3]){
    int rows1 = sizeof(matrix1)/sizeof(matrix1[0]);
    int rows2 = sizeof(matrix2)/sizeof(matrix2[0]);
    int columns2 = sizeof(matrix2[0])/sizeof(matrix2[0][0]);

    //check if the matrices can be multiplied
    if(rows1 != columns2){
        printf("Matrices cannot be multiplied.\n");
        return;
    }

    int result[rows1][columns2];

    for(int i=0; i<rows1; i++){
        for(int j=0; j<columns2; j++){
            int sum = 0;
            for(int k=0; k<rows2; k++){
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }

    //print the result matrix
    printf("Result matrix:\n");
    printMatrix(result, rows1, columns2);
}

int main(){
    int matrix1[3][3] = {{2, 4, 6},
                        {8, 10, 12},
                        {14, 16, 18}};

    int matrix2[3][3] = {{1, 3, 5},
                        {7, 9, 11},
                        {13, 15, 17}};
                        
    //print the matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, 3, 3);
    
    //perform matrix multiplication
    matrixMultiply(matrix1, matrix2);

    return 0;
}