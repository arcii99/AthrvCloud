//FormAI DATASET v1.0 Category: Scientific ; Style: creative
#include<stdio.h>

/* This program calculates and prints the determinant of a 3x3 matrix */

int main(){
    // Initializing the matrix
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Printing the matrix for visualization purposes
    printf("3x3 Matrix:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculating the determinant of the matrix
    int det = matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[2][1]*matrix[1][2]) - matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[2][0]*matrix[1][2]) + matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[2][0]*matrix[1][1]);

    // Printing the determinant
    printf("\nDeterminant of the matrix: %d", det);

    return 0;
}