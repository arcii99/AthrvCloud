//FormAI DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>

int main() {

    printf("Welcome to the matrix operations program!\n");

    int matrix1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matrix2[3][3] = {{9,8,7}, {6,5,4}, {3,2,1}};
    int resultMatrix[3][3];

    printf("\nFirst Matrix:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("\nSecond Matrix:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    // Addition of matrices
    printf("\nAdding the two matrices...\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nResultant Matrix:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    // Multiplication of matrices
    printf("\nMultiplying the two matrices...\n");
    int sum;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            sum = 0;
            for(int k=0; k<3; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            resultMatrix[i][j] = sum;
        }
    }

    printf("\nResultant Matrix:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nThank you for using the matrix operations program!");

    return 0;
}