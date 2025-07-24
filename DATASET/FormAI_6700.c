//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if(b == 0) {
        printf("Error: division by zero\n");
        return NAN;
    }
    return a / b;
}

// Function to perform modulus
double modulus(double a, double b) {
    if(b == 0) {
        printf("Error: division by zero\n");
        return NAN;
    }
    return fmod(a, b);
}

// Function to perform power
double power(double a, double b) {
    return pow(a, b);
}

// Function to perform square root
double sqrt_fun(double a) {
    if(a < 0) {
        printf("Error: square root of negative number\n");
        return NAN;
    }
    return sqrt(a);
}

// Function to perform absolute value
double abs_fun(double a) {
    return fabs(a);
}

int main() {
    char operation;
    double op1, op2, result;
    bool exit_flag = false;
    
    while(!exit_flag) {
        // Display menu
        printf("Choose an operation:\n");
        printf("+ Addition\n- Subtraction\n* Multiplication\n/ Division\n%% Modulus\n^ Power\ns Square Root\na Absolute Value\nq Quit Calculator\n");
        
        // Accept user input for operation
        printf("Enter operation: ");
        scanf(" %c", &operation);
        
        // Check if user wants to quit
        if(operation == 'q') {
            exit_flag = true;
        } else {
            // Accept user inputs for operands
            printf("Enter first operand: ");
            scanf("%lf", &op1);
            if(operation != 's' && operation != 'a') {
                printf("Enter second operand: ");
                scanf("%lf", &op2);
            }
            
            // Perform operation and display result
            switch(operation) {
                case '+':
                    result = add(op1, op2);
                    printf("Result: %lf\n", result);
                    break;
                case '-':
                    result = subtract(op1, op2);
                    printf("Result: %lf\n", result);
                    break;
                case '*':
                    result = multiply(op1, op2);
                    printf("Result: %lf\n", result);
                    break;
                case '/':
                    result = divide(op1, op2);
                    printf("Result: %lf\n", result);
                    break;
                case '%':
                    result = modulus(op1, op2);
                    printf("Result: %lf\n", result);
                    break;
                case '^':
                    result = power(op1, op2);
                    printf("Result: %lf\n", result);
                    break;
                case 's':
                    result = sqrt_fun(op1);
                    printf("Result: %lf\n", result);
                    break;
                case 'a':
                    result = abs_fun(op1);
                    printf("Result: %lf\n", result);
                    break;
                default:
                    printf("Invalid operation\n");
                    break;
            }
        }
    }
    
    return 0;
}