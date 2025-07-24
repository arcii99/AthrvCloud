//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void add();
void subtract();
void multiply();
void divide();
void exponent();
void factorial();
void logarithm();

int main() {
    int choice;

    printf("Welcome to the Scientific Calculator!\n");

    do {
        printf("\nPlease choose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exponentiation\n");
        printf("6. Factorial\n");
        printf("7. Logarithm\n");
        printf("8. Exit program\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                exponent();
                break;
            case 6:
                factorial();
                break;
            case 7:
                logarithm();
                break;
            case 8:
                printf("Thank you for using the Scientific Calculator!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}

void add() {
    double num1, num2, sum;

    printf("Please enter the first number:\n");
    scanf("%lf", &num1);

    printf("Please enter the second number:\n");
    scanf("%lf", &num2);

    sum = num1 + num2;

    printf("%.2lf + %.2lf = %.2lf\n", num1, num2, sum);
}

void subtract() {
    double num1, num2, difference;

    printf("Please enter the first number:\n");
    scanf("%lf", &num1);

    printf("Please enter the second number:\n");
    scanf("%lf", &num2);

    difference = num1 - num2;

    printf("%.2lf - %.2lf = %.2lf\n", num1, num2, difference);
}

void multiply() {
    double num1, num2, product;

    printf("Please enter the first number:\n");
    scanf("%lf", &num1);

    printf("Please enter the second number:\n");
    scanf("%lf", &num2);

    product = num1 * num2;

    printf("%.2lf * %.2lf = %.2lf\n", num1, num2, product);
}

void divide() {
    double num1, num2, quotient;

    printf("Please enter the first number:\n");
    scanf("%lf", &num1);

    printf("Please enter the second number:\n");
    scanf("%lf", &num2);

    if (num2 == 0) {
        printf("Invalid input. Cannot divide by zero.\n");
        return;
    }

    quotient = num1 / num2;

    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, quotient);
}

void exponent() {
    double base, exponent, result;

    printf("Please enter the base:\n");
    scanf("%lf", &base);

    printf("Please enter the exponent:\n");
    scanf("%lf", &exponent);

    result = pow(base, exponent);

    printf("%.2lf raised to the power of %.2lf is %.2lf\n", base, exponent, result);
}

void factorial() {
    int num, i;
    double result = 1;

    printf("Please enter a positive integer:\n");
    scanf("%d", &num);

    if (num < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return;
    }

    for (i = 1; i <= num; i++) {
        result *= i;
    }

    printf("%d! is %.2lf\n", num, result);
}

void logarithm() {
    double num, base, result;

    printf("Please enter the number:\n");
    scanf("%lf", &num);

    printf("Please enter the base:\n");
    scanf("%lf", &base);

    if (num <= 0 || base <= 0) {
        printf("Invalid input. Please enter positive numbers.\n");
        return;
    }

    result = log(num) / log(base);

    printf("Log base %.2lf of %.2lf is %.2lf\n", base, num, result);
}