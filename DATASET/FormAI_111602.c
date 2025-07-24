//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ephemeral
#include <stdio.h>
#include <math.h>

// Function to add two numbers
double add(double x, double y) {
    return x + y;
}

// Function to subtract two numbers
double subtract(double x, double y) {
    return x - y;
}

// Function to multiply two numbers
double multiply(double x, double y) {
    return x * y;
}

// Function to divide two numbers
double divide(double x, double y) {
    if (y == 0) {
        printf("Error: Cannot divide by zero");
        return 0;
    }
    return x / y;
}

// Function to calculate power of a number
double power(double x, double y) {
    return pow(x, y);
}

// Function to calculate square root of a number
double sqrt(double x) {
    if (x < 0) {
        printf("Error: Cannot calculate square root of negative number");
        return 0;
    }
    return sqrt(x);
}

// Main function
int main() {
    double firstNum, secondNum, result;
    char operator;

    // User input
    printf("Enter a mathematical expression: ");
    scanf("%lf %c %lf", &firstNum, &operator, &secondNum);

    // Switch statement to perform respective operation based on operator
    switch(operator) {
        case '+':
            result = add(firstNum, secondNum);
            printf("%.2lf + %.2lf = %.2lf", firstNum, secondNum, result);
            break;
        case '-':
            result = subtract(firstNum, secondNum);
            printf("%.2lf - %.2lf = %.2lf", firstNum, secondNum, result);
            break;
        case '*':
            result = multiply(firstNum, secondNum);
            printf("%.2lf * %.2lf = %.2lf", firstNum, secondNum, result);
            break;
        case '/':
            result = divide(firstNum, secondNum);
            printf("%.2lf / %.2lf = %.2lf", firstNum, secondNum, result);
            break;
        case '^':
            result = power(firstNum, secondNum);
            printf("%.2lf ^ %.2lf = %.2lf", firstNum, secondNum, result);
            break;
        case 'sqrt':
            result = sqrt(firstNum);
            printf("sqrt(%.2lf) = %.2lf", firstNum, result);
            break;
        default:
            printf("Error: Invalid operator");
    }

    return 0;
}