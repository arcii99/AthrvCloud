//FormAI DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>

int main() {
    int matrixA[3][3], matrixB[3][3], result[3][3];
    int i, j, k, sum;

    // Get input for matrixA
    printf("Enter Matrix A elements:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Get input for matrixB
    printf("\nEnter Matrix B elements:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Multiplying matrices A and B
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            sum = 0;
            for(k=0; k<3; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            result[i][j] = sum;
        }
    }

    // Displaying result matrix
    printf("\nResultant Matrix:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}