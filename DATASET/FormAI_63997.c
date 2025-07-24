//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// function declarations
double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
double power(double, double);
double sine(double);
double cosine(double);
double tangent(double);
double square_root(double);
int is_number(char*);

// main function
int main() {
    double num1, num2, result;
    char operation, choice[100];

    do {
        printf("\nEnter operation (+, -, *, /, ^, sin, cos, tan, sqrt): ");
        scanf(" %c", &operation);

        switch(operation) {
            case '+':
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = addition(num1, num2);
                printf("Result: %.2f", result);
                break;
            case '-':
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = subtraction(num1, num2);
                printf("Result: %.2f", result);
                break;
            case '*':
                printf("\nEnter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = multiplication(num1, num2);
                printf("Result: %.2f", result);
                break;
            case '/':
                printf("\nEnter dividend: ");
                scanf("%lf", &num1);
                printf("Enter divisor: ");
                scanf("%lf", &num2);

                // check if divisor is zero
                if(num2 == 0) {
                    printf("Error: Division by zero!");
                } else {
                    result = division(num1, num2);
                    printf("Result: %.2f", result);
                }
                break;
            case '^':
                printf("\nEnter base: ");
                scanf("%lf", &num1);
                printf("Enter exponent: ");
                scanf("%lf", &num2);
                result = power(num1, num2);
                printf("Result: %.2f", result);
                break;
            case 's':
                printf("\nEnter operand (in degrees): ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("Result: %.2f", result);
                break;
            case 'c':
                printf("\nEnter operand (in degrees): ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("Result: %.2f", result);
                break;
            case 't':
                printf("\nEnter operand (in degrees): ");
                scanf("%lf", &num1);
                // check if tangent is undefined
                if(fmod(num1, 90) == 0 && fmod(num1, 180) != 0) {
                    printf("Error: Tan undefined for given operand!");
                } else {
                    result = tangent(num1);
                    printf("Result: %.2f", result);
                }
                break;
            case 'sq':
                printf("\nEnter operand: ");
                scanf("%lf", &num1);
                // check if operand is negative
                if(num1 < 0) {
                    printf("Error: Square root of negative number is undefined!");
                } else {
                    result = square_root(num1);
                    printf("Result: %.2f", result);
                }
                break;
            default:
                printf("Invalid operation!");
        }

        // ask user if they want to perform another operation
        printf("\n\nDo you want to perform another operation? (y/n): ");
        scanf("%s", choice);
    } while(choice[0] == 'y' || choice[0] == 'Y');

    return 0;
}

// function definitions

double addition(double num1, double num2) {
    return num1 + num2;
}

double subtraction(double num1, double num2) {
    return num1 - num2;
}

double multiplication(double num1, double num2) {
    return num1 * num2;
}

double division(double num1, double num2) {
    return num1 / num2;
}

double power(double num1, double num2) {
    return pow(num1, num2);
}

double sine(double operand) {
    double radian = operand * (M_PI / 180);
    return sin(radian);
}

double cosine(double operand) {
    double radian = operand * (M_PI / 180);
    return cos(radian);
}

double tangent(double operand) {
    double radian = operand * (M_PI / 180);
    return tan(radian);
}

double square_root(double operand) {
    return sqrt(operand);
}

int is_number(char* str) {
    int i, decimal_count = 0;

    for(i = 0; str[i] != '\0'; i++) {
        if(!isdigit(str[i])) {
            if(str[i] == '.') {
                decimal_count++;
                if(decimal_count > 1) {
                    return 0;
                }
            } else {
                return 0;
            }
        }
    }

    return 1;
}