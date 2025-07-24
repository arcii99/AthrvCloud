//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: cheerful
#include <stdio.h>
#include <math.h>

int main() {
    int option;
    float num1, num2, result;
    printf("\nWelcome to the happy scientific calculator!\n\n");
    do {
        printf("Please select an operation from the following options:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power function\n6. Square root function\n7. Exit\n\n");
        scanf("%d", &option);
        printf("\n");
        switch (option) {
            case 1:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = num1 + num2;
                printf("\n%.2f + %.2f = %.2f\n\n", num1, num2, result);
                break;
            case 2:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = num1 - num2;
                printf("\n%.2f - %.2f = %.2f\n\n", num1, num2, result);
                break;
            case 3:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                result = num1 * num2;
                printf("\n%.2f * %.2f = %.2f\n\n", num1, num2, result);
                break;
            case 4:
                printf("Enter the first number: ");
                scanf("%f", &num1);
                printf("Enter the second number: ");
                scanf("%f", &num2);
                if (num2 == 0) {
                    printf("\nError: division by zero\n\n");
                } else {
                    result = num1 / num2;
                    printf("\n%.2f / %.2f = %.2f\n\n", num1, num2, result);
                }
                break;
            case 5:
                printf("Enter the base number: ");
                scanf("%f", &num1);
                printf("Enter the exponent number: ");
                scanf("%f", &num2);
                result = pow(num1, num2);
                printf("\n%.2f raised to the power of %.2f = %.2f\n\n", num1, num2, result);
                break;
            case 6:
                printf("Enter the number to find the square root of: ");
                scanf("%f", &num1);
                if (num1 < 0) {
                    printf("\nError: square root of a negative number is undefined\n\n");
                } else {
                    result = sqrt(num1);
                    printf("\nThe square root of %.2f is %.2f\n\n", num1, result);
                }
                break;
            case 7:
                printf("Thank you for using the happy scientific calculator! Have a great day!\n");
                break;
            default:
                printf("Invalid option selected. Please try again.\n\n");
                break;
        }
    } while (option != 7);
    return 0;
}