//FormAI DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printMatrix(int matrix[ROWS][COLS]){
    int i, j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS]){
    int i, j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            matrix1[i][j] += matrix2[i][j];
        }
    }
}

int main(){
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS];
    srand(time(0));
    int i, j;

    // Fill the matrices with random numbers between 1 and 10
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            matrix1[i][j] = rand()%10 + 1;
            matrix2[i][j] = rand()%10 + 1;
        }
    }

    // Print the original matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2);

    // Add the matrices
    addMatrix(matrix1, matrix2);

    // Print the result
    printf("\nMatrix 1 + Matrix 2:\n");
    printMatrix(matrix1);

    return 0;
}