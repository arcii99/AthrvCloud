//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Welcome to the Scientific Calculator\n");
    printf("Enter the operation you would like to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Exponential\n");
    printf("7. Logarithm\n");
    printf("8. Trigonometric Functions\n");

    int operation;
    scanf("%d", &operation);

    if(operation == 1 || operation == 2 || operation == 3 || operation == 4) {
        printf("Enter the first number: ");
        double num1;
        scanf("%lf", &num1);

        printf("Enter the second number: ");
        double num2;
        scanf("%lf", &num2);

        if(operation == 1) {
            printf("The result of %lf + %lf is %lf\n", num1, num2, num1 + num2);
        }
        else if(operation == 2) {
            printf("The result of %lf - %lf is %lf\n", num1, num2, num1 - num2);
        }
        else if(operation == 3) {
            printf("The result of %lf * %lf is %lf\n", num1, num2, num1 * num2);
        }
        else if(operation == 4) {
            if(num2 == 0) {
                printf("Cannot divide by zero\n");
            }
            else {
                printf("The result of %lf / %lf is %lf\n", num1, num2, num1 / num2);
            }
        }
    }
    else if(operation == 5) {
        printf("Enter the number: ");
        double num;
        scanf("%lf", &num);

        if(num < 0) {
            printf("Cannot calculate square root of a negative number\n");
        }
        else {
            printf("The result of sqrt(%lf) is %lf\n", num, sqrt(num));
        }
    }
    else if(operation == 6) {
        printf("Enter the base number: ");
        double base;
        scanf("%lf", &base);

        printf("Enter the exponent: ");
        double exponent;
        scanf("%lf", &exponent);

        printf("The result of %lf raised to the power of %lf is %lf\n", base, exponent, pow(base, exponent));
    }
    else if(operation == 7) {
        printf("Enter the number: ");
        double num;
        scanf("%lf", &num);

        if(num <= 0) {
            printf("Cannot calculate logarithm of a non-positive number\n");
        }
        else {
            printf("Enter the base: ");
            double base;
            scanf("%lf", &base);

            printf("The result of log base %lf of %lf is %lf\n", base, num, log(num) / log(base));
        }
    }
    else if(operation == 8) {
        printf("Enter the angle in degrees: ");
        double angle;
        scanf("%lf", &angle);

        double radians = angle * (M_PI / 180);

        printf("The trigonometric functions of %lf degrees are:\n", angle);
        printf("sin(%lf) = %lf\n", angle, sin(radians));
        printf("cos(%lf) = %lf\n", angle, cos(radians));
        printf("tan(%lf) = %lf\n", angle, tan(radians));
    }
    else {
        printf("Invalid operation\n");
    }

    return 0;
}