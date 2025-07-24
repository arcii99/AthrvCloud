//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    printf("Welcome to the Scientific Calculator\n");

    while (true) {
        printf("Enter the operation you want to perform:\n"
               "1. Addition\n"
               "2. Subtraction\n"
               "3. Multiplication\n"
               "4. Division\n"
               "5. Exponential\n"
               "6. Logarithm\n"
               "7. Sine\n"
               "8. Cosine\n"
               "9. Tangent\n"
               "10. Square Root\n"
               "11. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter two numbers to add:\n");
                double num1, num2;
                scanf("%lf%lf", &num1, &num2);
                double sum = num1 + num2;
                printf("Sum = %.2lf\n", sum);
                break;
            }
            case 2: {
                printf("Enter two numbers to subtract:\n");
                double num1, num2;
                scanf("%lf%lf", &num1, &num2);
                double diff = num1 - num2;
                printf("Difference = %.2lf\n", diff);
                break;
            }
            case 3: {
                printf("Enter two numbers to multiply:\n");
                double num1, num2;
                scanf("%lf%lf", &num1, &num2);
                double prod = num1 * num2;
                printf("Product = %.2lf\n", prod);
                break;
            }
            case 4: {
                printf("Enter two numbers to divide:\n");
                double num1, num2;
                scanf("%lf%lf", &num1, &num2);
                double quo = num1 / num2;
                printf("Quotient = %.2lf\n", quo);
                break;
            }
            case 5: {
                printf("Enter the base and power for exponential:\n");
                double base, power;
                scanf("%lf%lf", &base, &power);
                double res = pow(base, power);
                printf("Result = %.2lf\n", res);
                break;
            }
            case 6: {
                printf("Enter the number for logarithm:\n");
                double num;
                scanf("%lf", &num);
                double res = log10(num);
                printf("Result = %.2lf\n", res);
                break;
            }
            case 7: {
                printf("Enter the angle in radians for sine:\n");
                double angle;
                scanf("%lf", &angle);
                double res = sin(angle);
                printf("Result = %.2lf\n", res);
                break;
            }
            case 8: {
                printf("Enter the angle in radians for cosine:\n");
                double angle;
                scanf("%lf", &angle);
                double res = cos(angle);
                printf("Result = %.2lf\n", res);
                break;
            }
            case 9: {
                printf("Enter the angle in radians for tangent:\n");
                double angle;
                scanf("%lf", &angle);
                double res = tan(angle);
                printf("Result = %.2lf\n", res);
                break;
            }
            case 10: {
                printf("Enter the number for square root:\n");
                double num;
                scanf("%lf", &num);
                double res = sqrt(num);
                printf("Result = %.2lf\n", res);
                break;
            }
            case 11: {
                printf("Goodbye!\n");
                exit(0);
            }
            default:
                printf("Invalid choice. Please enter a number from 1 to 11.\n");
                break;
        }
    }
    return 0;
}