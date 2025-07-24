//FormAI DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int option, row, col, i, j;
    printf("Welcome to the Matrix Operations Program.\n");
    printf("Please enter the number of rows and columns you would like for your matrix:\n");
    scanf("%d %d", &row, &col);
    int matrix[row][col];

    printf("Enter the elements of your Matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The Matrix you entered is:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    while (1) {
        printf("Choose one of the following operations:\n");
        printf("1. Transpose the Matrix\n");
        printf("2. Find the sum of all elements in the Matrix\n");
        printf("3. Multiply the Matrix by a scalar\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("The Transpose of the Matrix is:\n");
                for (i = 0; i < col; i++) {
                    for (j = 0; j < row; j++) {
                        printf("%d ", matrix[j][i]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                int sum = 0;
                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        sum += matrix[i][j];
                    }
                }
                printf("The Sum of all elements in the Matrix is: %d\n", sum);
                break;

            case 3:
                int scalar;
                printf("Enter the scalar to multiply the Matrix with:\n");
                scanf("%d", &scalar);
                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        matrix[i][j] *= scalar;
                    }
                }
                printf("The Matrix after multiplication with scalar is:\n");
                for (i = 0; i < row; i++) {
                    for (j = 0; j < col; j++) {
                        printf("%d ", matrix[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Thank you for using the Matrix Operations Program!\n");
                exit(0);
                break;

            default:
                printf("Invalid Option! Please choose a valid option.\n");
                break;
        }
    }
    return 0;
}