//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform addition operation
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction operation
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication operation
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division operation
double divide(double a, double b) {
    return a / b;
}

// Function to calculate power of a number
double power(double a, double b) {
    return pow(a, b);
}

// Function to calculate square root of a number
double square_root(double a) {
    return sqrt(a);
}

// Function to calculate logarithm of a number
double logarithm(double a) {
    return log10(a);
}

int main() {
    int choice;
    double num1, num2, result;
    
    printf("Welcome to the scientific calculator.\n\n");
    
    while(1) {
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square root\n");
        printf("7. Logarithm (base 10)\n");
        printf("8. Exit\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %lf\n", result);
                break;
                
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %lf\n", result);
                break;
                
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %lf\n", result);
                break;
                
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                
                if(num2 == 0) {
                    printf("Error: Division by zero.\n");
                }
                else {
                    result = divide(num1, num2);
                    printf("Result: %lf\n", result);
                }
                
                break;
                
            case 5:
                printf("Enter base number and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("Result: %lf\n", result);
                break;
                
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                
                if(num1 < 0) {
                    printf("Error: Cannot calculate square root of a negative number.\n");
                }
                else {
                    result = square_root(num1);
                    printf("Result: %lf\n", result);
                }
                
                break;
                
            case 7:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                
                if(num1 <= 0) {
                    printf("Error: Cannot calculate logarithm of a non-positive number.\n");
                }
                else {
                    result = logarithm(num1);
                    printf("Result: %lf\n", result);
                }
                
                break;
            
            case 8:
                printf("Exiting the program.\n");
                exit(0);
                break;
                
            default:
                printf("Error: Invalid choice.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}