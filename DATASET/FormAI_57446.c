//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <math.h>

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    return a / b;
}

// Function to find square root of a number
double squareRoot(double a) {
    return sqrt(a);
}

// Function to find power of a number
double power(double a, double b) {
    return pow(a, b);
}

int main() {
    int choice;
    double num1, num2, result;
    
    printf("Welcome to Invasive Scientific Calculator!\n\n");
    
    do {
        printf("Choose an operation:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Square Root\n");
        printf("6. Power\n");
        printf("7. Exit\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %lf\n\n", result);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %lf\n\n", result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %lf\n\n", result);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                printf("Result: %lf\n\n", result);
                break;
            case 5:
                printf("Enter a number to find its square root: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                printf("Result: %lf\n\n", result);
                break;
            case 6:
                printf("Enter a base number: ");
                scanf("%lf", &num1);
                printf("Enter the power: ");
                scanf("%lf", &num2);
                result = power(num1, num2);
                printf("Result: %lf\n\n", result);
                break;
            case 7:
                printf("Thanks for using Invasive Scientific Calculator!\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n\n");
        }
        
    } while(choice != 7);
    
    return 0;
}