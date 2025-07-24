//FormAI DATASET v1.0 Category: Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Welcome to the shockingly unique Calculator program!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Factorial\n");
    printf("8. Absolute Value\n");

    int choice;
    double num1, num2, result;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("The result of %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("The result of %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("The result of %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 == 0) {
                printf("Error! Division by zero is not allowed.");
                break;
            }
            result = num1 / num2;
            printf("The result of %.2lf / %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 5:
            printf("Enter a base and a power: ");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("The result of %.2lf to the power of %.2lf is %.2lf\n", num1, num2, result);
            break;
        case 6:
            printf("Enter a number to find the square root of: ");
            scanf("%lf", &num1);
            if (num1 < 0) {
                printf("Error! Cannot find square root of negative numbers.");
                break;
            }
            result = sqrt(num1);
            printf("The square root of %.2lf is %.2lf\n", num1, result);
            break;
        case 7:
            printf("Enter a number to find the factorial of: ");
            scanf("%lf", &num1);
            if (num1 < 0) {
                printf("Error! Cannot find factorial of negative numbers.");
                break;
            }
            result = 1;
            for(int i = 1; i <= num1; i++) {
                result *= i;
            }
            printf("The factorial of %.2lf is %.2lf\n", num1, result);
            break;
        case 8:
            printf("Enter a number to find the absolute value of: ");
            scanf("%lf", &num1);
            result = fabs(num1);
            printf("The absolute value of %.2lf is %.2lf\n", num1, result);
            break;
        default:
            printf("Invalid choice!");
            break;
    }

    printf("\nThank you for using this shocking Calculator program.");

    return 0;
}