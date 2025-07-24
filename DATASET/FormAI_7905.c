//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <math.h>

int main() {
    int choice; // var to store user choice
    float num1, num2, result; // vars to store numbers and results
    printf("Welcome to the puzzling calculator program\n");
    while (1) { // continuous loop until user decides to quit
        printf("\nChoose between the following options:\n");
        printf("1. Add two numbers\n");
        printf("2. Subtract two numbers\n");
        printf("3. Multiply two numbers\n");
        printf("4. Divide two numbers\n");
        printf("5. Calculate the power of a number\n");
        printf("6. Calculate the square root of a number\n");
        printf("7. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter two numbers to add:\n");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
                break;

            case 2:
                printf("\nEnter two numbers to subtract:\n");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
                break;

            case 3:
                printf("\nEnter two numbers to multiply:\n");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("\n%.2f * %.2f = %.2f\n", num1, num2, result);
                break;

            case 4:
                printf("\nEnter two numbers to divide:\n");
                scanf("%f %f", &num1, &num2);
                if (num2 == 0) {
                    printf("\nError: division by zero is undefined!\n");
                } else {
                    result = num1 / num2;
                    printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;

            case 5:
                printf("\nEnter the number and the power to raise:\n");
                scanf("%f %f", &num1, &num2);
                result = pow(num1, num2);
                printf("\n%.2f raised to %.2f = %.2f\n", num1, num2, result);
                break;

            case 6:
                printf("\nEnter a number to calculate its square root:\n");
                scanf("%f", &num1);
                if (num1 < 0) {
                    printf("\nError: square root of negative number is undefined!\n");
                } else {
                    result = sqrt(num1);
                    printf("\nSquare root of %.2f = %.2f\n", num1, result);
                }
                break;

            case 7:
                printf("\nThank you for choosing the puzzling calculator!\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    }
}