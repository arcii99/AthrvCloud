//FormAI DATASET v1.0 Category: Calculator ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    float num1, num2, result;
    int choice;

    printf("Welcome to the Mathematical Calculator\n");
    printf("--------------------------------------\n\n");

    printf("Enter the first operand: ");
    scanf("%f", &num1);
    printf("Enter the second operand: ");
    scanf("%f", &num2);

    printf("\nSelect the operation you want to perform\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n\n");

    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("\n%.2f x %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            result = num1 / num2;
            if (num2 == 0) {
                printf("Cannot divide by zero!\n");
            } else {
                printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
            }
            break;
        case 5:
            result = pow(num1, num2);
            printf("\n%.2f ^ %.2f = %.2f\n", num1, num2, result);
            break;
        case 6:
            if (num1 < 0 || num2 < 0) {
                printf("\nSquare root of negative numbers is not possible!\n");
            } else {
                result = sqrt(num1);
                printf("\nSquare root of %.2f = %.2f\n", num1, result);
                result = sqrt(num2);
                printf("Square root of %.2f = %.2f\n", num2, result);
            }
            break;
        default:
            printf("\nInvalid choice!");
    }

    return 0;
}