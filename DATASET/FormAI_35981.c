//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>

int main() {
    int n;

    printf("How big do you want your matrix to be? ");
    scanf("%d", &n);

    int matrix[n][n];
    int i, j;

    printf("Let's start by filling your matrix!\n");

    // Filling the matrix with user input
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter the value at position (%d,%d): ", i, j);
            scanf("%d", &matrix[i][j]);
            printf("Great! You entered %d\n", matrix[i][j]);
        }
    }

    // Printing the matrix
    printf("\n\n Your Matrix is: \n\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n\n Now let's do some matrix operations!\n");

    // Finding the sum of all elements in the matrix
    int sum = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
    }
    printf("The sum of all elements in the matrix is %d\n", sum);

    // Finding the transpose of the matrix
    printf("\n\nThe transpose of the matrix is:\n\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    // Finding the product of the diagonal elements
    int product = 1;

    for (i = 0; i < n; i++) {
        product *= matrix[i][i];
    }

    printf("\n\nThe product of diagonal elements in the matrix is %d\n", product);

    // Finding the maximum element in the matrix
    int max = matrix[0][0];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }

    printf("\n\nThe maximum element in the matrix is %d\n", max);

    // Finding the minimum element in the matrix
    int min = matrix[0][0];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }

    printf("\n\nThe minimum element in the matrix is %d\n", min);

    return 0;
}