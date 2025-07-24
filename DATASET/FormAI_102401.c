//FormAI DATASET v1.0 Category: Computer Biology ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// function to calculate the factorial of a number
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int n, i, j;

    // get input from user
    printf("Enter a number: ");
    scanf("%d", &n);

    // create a 2D array to store the result of calculations
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // populate the matrix with factorials
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = factorial(i) + factorial(j);
        }
    }

    // print the matrix
    printf("Factorial Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}