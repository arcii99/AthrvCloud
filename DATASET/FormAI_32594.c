//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

/* This is a program that performs matrix operations on 3x3 matrices. */

int main()
{
    printf("Welcome to the matrix operations program!\n");

    // Declare and initialize matrices A, B, and C
    int A[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int B[3][3] = {{9,8,7}, {6,5,4}, {3,2,1}};
    int C[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};

    // Print out matrices A and B
    printf("\nMatrix A:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix B:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Add matrices A and B to get matrix C
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print out matrix C
    printf("\nMatrix C (A+B):\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Multiply matrix A by 5
    printf("\nMatrix A multiplied by 5:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            A[i][j] *= 5;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Multiply matrices A and B to get matrix C
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            C[i][j] = 0;
            for(int k=0; k<3; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print out matrix C
    printf("\nMatrix C (A*B):\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    printf("\nThanks for using the matrix operations program!\n");

    return 0;
}