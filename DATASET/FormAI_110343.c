//FormAI DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>

int main() {
    printf("Are you ready for some Matrix operations?\n");
    printf("I am so excited to show you the power of C!\n");

    // Let's create a 3x3 matrix
    int matrix[3][3] = {{4, 5, 6}, {8, 9, 10}, {12, 13, 14}};

    printf("\nHere's your matrix:\n");

    // Display the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nWow, this matrix looks amazing!\n");
    printf("Now let's find the determinant of this matrix:\n");
    
    // Calculate the determinant
    int det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) 
    - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]) 
    + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);

    printf("\nThe determinant is: %d\n", det);
    printf("That was so easy with C!\n");

    printf("\nLet's multiply this matrix by 2:\n");

    // Multiply the matrix by 2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] *= 2;
        }
    }

    printf("\nHere's your new matrix:\n");

    // Display the new matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nThat was some sweet matrix multiplication with C!\n");
    printf("I hope you enjoyed watching some incredible C magic...\n");
    printf("Goodbye for now!\n");

    return 0;
}