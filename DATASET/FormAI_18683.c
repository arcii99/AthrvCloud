//FormAI DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>

#define ROWS 3
#define COLS 3

// function to print a matrix
void printMatrix(int arr[ROWS][COLS]) {
    printf("\n");
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
void addMatrix(int arr1[ROWS][COLS],int arr2[ROWS][COLS]){
    int result[ROWS][COLS];
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    printf("\nAddition of Given Matrices:\n");
    printMatrix(result);
}

// function to subtract two matrices
void subMatrix(int arr1[ROWS][COLS],int arr2[ROWS][COLS]){
    int result[ROWS][COLS];
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    printf("\nSubtraction of Given Matrices:\n");
    printMatrix(result);
}

// function to multiply two matrices
void mulMatrix(int arr1[ROWS][COLS],int arr2[ROWS][COLS]){
    int result[ROWS][COLS];
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            result[i][j] = 0;
            for(int k=0;k<ROWS;k++){
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("\nMultiplication of Given Matrices:\n");
    printMatrix(result);
}

int main(){
    int matrix1[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrix2[ROWS][COLS] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("Matrix 2:\n");
    printMatrix(matrix2);
    
    addMatrix(matrix1,matrix2);
    subMatrix(matrix1,matrix2);
    mulMatrix(matrix1,matrix2);

    return 0;
}