//FormAI DATASET v1.0 Category: Matrix operations ; Style: innovative
#include <stdio.h>
#define SIZE 3 // Define the size of matrix

// Function to print the matrix
void printMatrix(int matrix[][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int matrix1[][SIZE], int matrix2[][SIZE], int result[][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int matrix1[][SIZE], int matrix2[][SIZE], int result[][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int matrix1[][SIZE], int matrix2[][SIZE], int result[][SIZE]){
    int sum; 
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            sum = 0;
            for(int k=0; k<SIZE; k++){
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main(){
    int matrix1[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
    int matrix2[SIZE][SIZE] = {{9,8,7},{6,5,4},{3,2,1}};
    int result[SIZE][SIZE];
    
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("Matrix 2:\n");
    printMatrix(matrix2);
    
    // Add the matrices
    addMatrix(matrix1, matrix2, result);
    printf("Matrix1 + Matrix2:\n");
    printMatrix(result);
    
    // Subtract the matrices
    subtractMatrix(matrix1, matrix2, result);
    printf("Matrix1 - Matrix2:\n");
    printMatrix(result);
    
    // Multiply the matrices
    multiplyMatrix(matrix1, matrix2, result);
    printf("Matrix1 * Matrix2:\n");
    printMatrix(result);
    
    return 0;
}