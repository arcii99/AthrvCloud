//FormAI DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int main(){

    // Initialize matrix A and matrix B
    int A[ROWS][COLS] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[ROWS][COLS] = {{9,8,7},{6,5,4},{3,2,1}};

    // Initialize matrix C with all zeros
    int C[ROWS][COLS] = {{0,0,0},{0,0,0},{0,0,0}};

    // Perform matrix addition
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Display matrix A
    printf("Matrix A:\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Display matrix B
    printf("Matrix B:\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Display matrix C
    printf("Matrix C (A + B):\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Perform matrix multiplication
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            int sum = 0;
            for(int k=0; k<COLS; k++){
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    // Display matrix A
    printf("Matrix A:\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Display matrix B
    printf("Matrix B:\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Display matrix C
    printf("Matrix C (A x B):\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}