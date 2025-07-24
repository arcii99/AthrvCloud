//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to Happy Calculator!\n");
    printf("This calculator can perform various scientific calculations :)\n\n");

    int choice;
    double num1, num2, result;
    char operation;

    do {
        printf("Choose an operation to perform:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exponentiation (^)\n");
        printf("6. Square Root (√)\n");
        printf("7. Absolute Value (|x|)\n");
        printf("8. Sine (sin)\n");
        printf("9. Cosine (cos)\n");
        printf("10. Tangent (tan)\n");
        printf("0. Exit Calculator :(\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1: // Addition
                printf("Enter two numbers separated by a space: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("%.2lf + %.2lf = %.2lf\n\n", num1, num2, result);
                break;

            case 2: // Subtraction
                printf("Enter two numbers separated by a space: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("%.2lf - %.2lf = %.2lf\n\n", num1, num2, result);
                break;

            case 3: // Multiplication
                printf("Enter two numbers separated by a space: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("%.2lf * %.2lf = %.2lf\n\n", num1, num2, result);
                break;
            
            case 4: // Division
                printf("Enter two numbers separated by a space: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Cannot divide by zero, please try again.\n\n");
                    break;
                }
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n\n", num1, num2, result);
                break;

            case 5: // Exponentiation
                printf("Enter two numbers separated by a space: ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("%.2lf ^ %.2lf = %.2lf\n\n", num1, num2, result);
                break;

            case 6: // Square Root
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 < 0) {
                    printf("Cannot find square root of a negative number, please try again.\n\n");
                    break;
                }
                result = sqrt(num1);
                printf("√%.2lf = %.2lf\n\n", num1, result);
                break;

            case 7: // Absolute Value
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = fabs(num1);
                printf("|%.2lf| = %.2lf\n\n", num1, result);
                break;

            case 8: // Sine
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * (M_PI/180));
                printf("sin(%.2lf) = %.2lf\n\n", num1, result);
                break;

            case 9: // Cosine
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = cos(num1 * (M_PI/180));
                printf("cos(%.2lf) = %.2lf\n\n", num1, result);
                break;

            case 10: // Tangent
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = tan(num1 * (M_PI/180));
                printf("tan(%.2lf) = %.2lf\n\n", num1, result);
                break;

            case 0: // Exit
                printf("Thank you for using Happy Calculator! Don't forget to smile :)\n");
                break;

            default:
                printf("Invalid input, please try again.\n\n");
                break;
        }

    } while(choice != 0);

    return 0;
}