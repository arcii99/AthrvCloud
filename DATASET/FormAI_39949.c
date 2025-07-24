//FormAI DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// A program to perform some unique matrix operations

int main() {
    int rows = 4, cols = 4, i, j, k, count = 0;
    int matrix[rows][cols];
    
    // initialize the matrix with values from 1 to 16
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            count++;
            matrix[i][j] = count;
        }
    }
    
    // print the original matrix
    printf("Original Matrix:\n");
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    // swap the top row and bottom row of the matrix
    for (j=0; j<cols; j++) {
        int temp = matrix[0][j];
        matrix[0][j] = matrix[rows-1][j];
        matrix[rows-1][j] = temp;
    }
    
    // print the matrix after swapping top row and bottom row
    printf("\nTop Row and Bottom Row Swapped:\n");
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    // update the diagonal elements of the matrix with values 1, 2, 3, and 4
    k = 1;
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            if (i == j) {
                matrix[i][j] = k;
                k++;
            }
        }
    }
    
    // print the matrix after updating diagonal elements
    printf("\nDiagonal Elements Updated:\n");
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    // create a new matrix with values 0
    int new_matrix[rows][cols];
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            new_matrix[i][j] = 0;
        }
    }
    
    // add the original matrix and new matrix element wise
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            new_matrix[i][j] += matrix[i][j];
            new_matrix[i][j] += new_matrix[i][j];
        }
    }
    
    // print the matrix after adding original matrix and new matrix element wise
    printf("\nOriginal Matrix and New Matrix Added Element Wise:\n");
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            printf("%d\t", new_matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}