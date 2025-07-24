//FormAI DATASET v1.0 Category: Matrix operations ; Style: excited
/* Get ready to experience the thrill of Matrix Operations in C! */

#include <stdio.h> // System I/O header file
#define ROWS 3 // Define constant values
#define COLS 3 

/* A function to print the results of matrix operations */
void printMatrix(int resultMatrix[ROWS][COLS]) {
    printf("\nResulting Matrix:\n"); // Output Header
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d\t", resultMatrix[i][j]); // Output each element
        }
        printf("\n"); // New line after each row
    }
}

int main() { // Start of the program
    
    printf("\nWelcome to the Matrix Operations in C demo!"); // Bring in the user
    printf("\nWe will perform some basic matrix operations today.\n");
    printf("\nFirst, let's learn about Matrix Addition.\n");

    int matrix1[ROWS][COLS] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}}; // Create matrix 1
    int matrix2[ROWS][COLS] = {{4, 4, 4}, {5, 5, 5}, {6, 6, 6}}; // Create matrix 2

    int resultMatrix[ROWS][COLS]; // Prepare a spot to put our results in

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j]; // Logic for matrix addition
        }
    }

    printMatrix(resultMatrix); // Call our function to print the result

    /* Next, let's do some matrix multiplication */

    printf("\nWoo! Matrix addition was easy. Let's try something more fun - Matrix Multiplication!\n");
    
    int matrix3[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Create matrix 3
    int matrix4[ROWS][COLS] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}; // Create matrix 4

    int newMatrix[ROWS][COLS]; // Create a new matrix for our results

    /* Logic for matrix multiplication */
    for(int i=0; i<ROWS; i++) { 
        for(int j=0; j<COLS; j++) {
            newMatrix[i][j] = 0;
            for(int k=0; k<ROWS; k++) {
                newMatrix[i][j] += matrix3[i][k] * matrix4[k][j];
            }
        }
    }

    printMatrix(newMatrix); // Call our function to print the result

    printf("\nWow! That was thrilling. See you soon for more Matrix Operations in C. BYE!!\n");

    return 0; // End the program
}