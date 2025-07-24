//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: grateful
#include <stdio.h>
#include <math.h>

int main() {
    printf("Welcome to the Grateful Scientific Calculator!\n");

    // Display menu options
    printf("Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponentiation\n");
    printf("6. Square Root\n");
    printf("7. Logarithm\n");
    printf("8. Trigonometric functions\n");
    printf("9. Quit\n");

    int choice = 0;

    while (choice != 9) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        double num1, num2, result;

        switch (choice) {
            case 1:
                printf("\nEnter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                printf("\nEnter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                printf("\nEnter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                printf("\nEnter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 5:
                printf("\nEnter the base: ");
                scanf("%lf", &num1);
                printf("Enter the exponent: ");
                scanf("%lf", &num2);
                result = pow(num1, num2);
                printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 6:
                printf("\nEnter the number: ");
                scanf("%lf", &num1);
                result = sqrt(num1);
                printf("sqrt(%.2lf) = %.2lf\n", num1, result);
                break;

            case 7:
                printf("\nEnter the number: ");
                scanf("%lf", &num1);
                result = log(num1);
                printf("log(%.2lf) = %.2lf\n", num1, result);
                break;

            case 8:
                printf("\nEnter the angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * M_PI / 180);
                printf("sin(%.2lf) = %.2lf\n", num1, result);
                result = cos(num1 * M_PI / 180);
                printf("cos(%.2lf) = %.2lf\n", num1, result);
                result = tan(num1 * M_PI / 180);
                printf("tan(%.2lf) = %.2lf\n", num1, result);
                break;

            case 9:
                printf("\nThank you for using the Grateful Scientific Calculator! Goodbye!\n");
                break;

            default:
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}