//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
#include <stdio.h>
#include <math.h>

const double PI = 3.141592653589793238;

int main()
{
    int choice;
    double num1, num2, result;

    printf("Welcome to the Scientific Calculator!\n");

    do {
        printf("\nWhat operation do you want to perform?\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Square root (√)\n");
        printf("6. Power (x^y)\n");
        printf("7. Sine (sin)\n");
        printf("8. Cosine (cos)\n");
        printf("9. Tangent (tan)\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("Result of %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("Result of %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("Result of %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero!\n");
                } else {
                    result = num1 / num2;
                    printf("Result of %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
            case 5:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                if (num1 < 0) {
                    printf("Error: Cannot calculate square root of a negative number!\n");
                } else {
                    result = sqrt(num1);
                    printf("Square root of %.2lf = %.2lf\n", num1, result);
                }
                break;
            case 6:
                printf("\nEnter base number: ");
                scanf("%lf", &num1);
                printf("Enter exponent number: ");
                scanf("%lf", &num2);
                result = pow(num1, num2);
                printf("%.2lf raised to the power of %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 7:
                printf("\nEnter a number in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * PI / 180.0);
                printf("Sine of %.2lf degrees = %.2lf\n", num1, result);
                break;
            case 8:
                printf("\nEnter a number in degrees: ");
                scanf("%lf", &num1);
                result = cos(num1 * PI / 180.0);
                printf("Cosine of %.2lf degrees = %.2lf\n", num1, result);
                break;
            case 9:
                printf("\nEnter a number in degrees: ");
                scanf("%lf", &num1);
                result = tan(num1 * PI / 180.0);
                printf("Tangent of %.2lf degrees = %.2lf\n", num1, result);
                break;
            case 10:
                printf("\nThank you for using the Scientific Calculator!\n");
                break;
            default:
                printf("\nInvalid choice! Please select a number from 1 to 10.\n");
                break;
        }
    } while (choice != 10);

    return 0;
}