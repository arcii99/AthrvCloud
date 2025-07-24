//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: visionary
#include <stdio.h>
#include <math.h>

// Function to perform addition operation
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to perform subtraction operation
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to perform multiplication operation
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to perform division operation
double divide(double num1, double num2) {
    return num1 / num2;
}

// Function to perform square root operation
double sqroot(double num) {
    return sqrt(num);
}

// Function to perform power operation
double power(double num, double exponent) {
    return pow(num, exponent);
}

// Function to perform modulus operation
double modulus(double num1, double num2) {
    return fmod(num1, num2);
}

int main() {

    double num1, num2, result;
    char operation;

    printf("Enter an arithmetic operation (+, -, *, /, sqrt, ^, mod): ");
    scanf("%c", &operation);

    switch(operation) {
        case '+':
            printf("Enter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            result = add(num1, num2);
            printf("The result is: %lf", result);
            break;
        case '-':
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            result = subtract(num1, num2);
            printf("The result is: %lf", result);
            break;
        case '*':
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            result = multiply(num1, num2);
            printf("The result is: %lf", result);
            break;
        case '/':
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            result = divide(num1, num2);
            printf("The result is: %lf", result);
            break;
        case 'sqrt':
            printf("Enter a number to find its square root: ");
            scanf("%lf", &num1);
            result = sqroot(num1);
            printf("The result is: %lf", result);
            break;
        case '^':
            printf("Enter a number and its exponent: ");
            scanf("%lf %lf", &num1, &num2);
            result = power(num1, num2);
            printf("The result is: %lf", result);
            break;
        case 'mod':
            printf("Enter two numbers to find modulus: ");
            scanf("%lf %lf", &num1, &num2);
            result = modulus(num1, num2);
            printf("The result is: %lf", result);
            break;
        default:
            printf("Invalid operation. Please enter a valid operator.");
    }

    return 0;
}