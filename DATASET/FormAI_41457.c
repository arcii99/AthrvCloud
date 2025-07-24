//FormAI DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Artistic Error Handling Program
int main() {

    // Input two integers
    int num1, num2;
    printf("Please enter two integers: ");
    if(scanf("%d%d", &num1, &num2) != 2) {
        fprintf(stderr, "Error: Input is not in the correct format, please enter two integers separated by a space.\n");
        exit(EXIT_FAILURE);
    }

    // Divide the first number by the second number
    if(num2 == 0) {
        fprintf(stderr, "Error: Division by zero is not allowed.\n");
        exit(EXIT_FAILURE);
    }
    int result = num1 / num2;

    // Check if the result is negative
    if(result < 0) {
        printf("Error: The result is negative. Do you want to continue (y/n)? ");
        char choice;
        scanf(" %c", &choice);
        if(choice != 'y' && choice != 'Y') {
            fprintf(stderr, "Program stopped by user.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Check if the result is larger than 100
    if(result > 100) {
        printf("Warning: The result is larger than 100. Do you want to continue (y/n)? ");
        char choice;
        scanf(" %c", &choice);
        if(choice != 'y' && choice != 'Y') {
            printf("Program stopped by user.\n");
            exit(EXIT_SUCCESS);
        }
    }

    // Print the result
    printf("%d / %d = %d\n", num1, num2, result);

    return 0;
}