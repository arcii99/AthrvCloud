//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>

// This is a hilarious matrix program
int main() {
    int rows, cols, i, j, menuOption;
    printf("Welcome to the hilarious matrix program!\n");

    // Get matrix dimensions from user
    printf("\nEnter the number of rows for your matrix: ");
    scanf("%d", &rows);
    printf("Now, enter the number of columns for your matrix: ");
    scanf("%d", &cols);

    // Declare the matrix
    int matrix[rows][cols];

    // Get values for matrix from user
    printf("\nTime to fill up your matrix with some funny numbers!\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter a funny number for row %d, column %d: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Let the user choose what to do with their matrix
    printf("\nWhat funny matrix operation would you like to perform?\n");
    printf("1. Transpose the matrix\n");
    printf("2. Find the maximum value in the matrix\n");
    printf("3. Find the sum of all values in the matrix\n");
    printf("4. Multiply the matrix by a funny scalar\n");
    printf("5. Exit the program\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &menuOption);

    switch (menuOption) {
        case 1:
            // Transpose the matrix
            printf("\nThe transpose of your hilarious matrix is:\n");
            for (i = 0; i < cols; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%d ", matrix[j][i]);
                }
                printf("\n");
            }
            break;

        case 2:
            // Find the maximum value in the matrix
            int max = matrix[0][0];
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    if (matrix[i][j] > max) {
                        max = matrix[i][j];
                    }
                }
            }
            printf("\nThe maximum value in your hilarious matrix is: %d\n", max);
            break;

        case 3:
            // Find the sum of all values in the matrix
            int sum = 0;
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    sum += matrix[i][j];
                }
            }
            printf("\nThe sum of all the funny numbers in your matrix is: %d\n", sum);
            break;

        case 4:
            // Multiply the matrix by a funny scalar
            int scalar;
            printf("\nWhat funny scalar would you like to multiply your matrix by? ");
            scanf("%d", &scalar);
            printf("\nAfter multiplying your hilarious matrix by %d, it looks like this:\n", scalar);
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    matrix[i][j] *= scalar;
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            break;

        case 5:
            // Exit the program
            printf("\nThanks for playing with the hilarious matrix program! Goodbye!\n");
            break;

        default:
            // Invalid menu option
            printf("\nInvalid menu option. Try again!\n");
            break;
    }

    return 0;
}