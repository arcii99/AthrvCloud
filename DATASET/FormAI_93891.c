//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function declarations
double addition(double x, double y);
double subtraction(double x, double y);
double multiplication(double x, double y);
double division(double x, double y);
double power(double x, int y);
double squareroot(double x);
double logarithm(double x);
void display_menu();

// main function
int main() {
    int choice;
    double num1, num2;
    printf("Welcome to the Scientific Calculator!\n\n");
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                printf("Result: %lf\n\n", addition(num1, num2));
                break;
            case 2:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                printf("Result: %lf\n\n", subtraction(num1, num2));
                break;
            case 3:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                printf("Result: %lf\n\n", multiplication(num1, num2));
                break;
            case 4:
                printf("Enter the first number: ");
                scanf("%lf", &num1);
                printf("Enter the second number: ");
                scanf("%lf", &num2);
                if(num2 == 0) {
                    printf("Error: Division by zero!\n\n");
                } else {
                    printf("Result: %lf\n\n", division(num1, num2));
                }
                break;
            case 5:
                printf("Enter the base number: ");
                scanf("%lf", &num1);
                printf("Enter the exponent: ");
                scanf("%lf", &num2);
                printf("Result: %lf\n\n", power(num1, (int)num2));
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Result: %lf\n\n", squareroot(num1));
                break;
            case 7:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if(num1 <= 0) {
                    printf("Error: Invalid input for logarithm!\n\n");
                } else {
                    printf("Result: %lf\n\n", logarithm(num1));
                }
                break;
            case 8:
                printf("Thanks for using the Scientific Calculator!\n");
                exit(0);
            default:
                printf("Invalid Input.\n\n");
        }
    } while(choice != 8);
    return 0;
}

// function definitions
void display_menu() {
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power function\n");
    printf("6. Square root function\n");
    printf("7. Logarithm function\n");
    printf("8. Exit\n\n");
    printf("Enter your choice: ");
}

double addition(double x, double y) {
    return x + y;
}

double subtraction(double x, double y) {
    return x - y;
}

double multiplication(double x, double y) {
    return x * y;
}

double division(double x, double y) {
    return x / y;
}

double power(double x, int y) {
    return pow(x, y);
}

double squareroot(double x) {
    return sqrt(x);
}

double logarithm(double x) {
    return log(x);
}