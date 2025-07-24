//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the matrix world, Neo!\n");
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int selection = 0;
    printf("Choose your action from the options below:\n");
    printf("1: Print the matrix\n");
    printf("2: Transpose the matrix\n");
    printf("3: Multiply the matrix with a scalar\n");
    scanf("%d", &selection);

    switch(selection) {
        case 1:
            printf("You have chosen to print the matrix:\n");
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            printf("You have chosen to transpose the matrix:\n");
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    printf("%d ", matrix[j][i]);
                }
                printf("\n");
            }
            break;
        case 3:
            int scalar = 0;
            printf("You have chosen to multiply the matrix with a scalar. Enter the scalar value: ");
            scanf("%d", &scalar);
            printf("The result is:\n");
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    printf("%d ", matrix[i][j] * scalar);
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid option. You are not the chosen one, Neo.\n");
            break;
    }
    printf("Remember, there is no spoon.\n");
    return 0;
}