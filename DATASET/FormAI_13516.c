//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: unmistakable
#include <stdio.h>
#include <math.h>

// Function to clear standard input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add two numbers
void add(double num1, double num2) {
    printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
}

// Function to subtract two numbers
void subtract(double num1, double num2) {
    printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
}

// Function to multiply two numbers
void multiply(double num1, double num2) {
    printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
}

// Function to divide two numbers
void divide(double num1, double num2) {
    if (num2 == 0) {
        printf("Error: division by zero\n");
    } else {
        printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
    }
}

// Function to find the square root of a number
void squareRoot(double num) {
    if (num < 0) {
        printf("Error: square root of negative number\n");
    } else {
        printf("sqrt(%.2lf) = %.2lf\n", num, sqrt(num));
    }
}

// Function to find the power of a number
void power(double num1, double num2) {
    printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, pow(num1, num2));
}

int main() {
    char choice;
    double num1, num2;
    
    while (1) {
        // Display menu
        printf("Scientific Calculator\n");
        printf("========================\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Square Root\n6. Power\n7. Quit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        
        // Perform operation based on user choice
        switch (choice) {
            case '1': // Addition
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                add(num1, num2);
                break;
            case '2': // Subtraction
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                subtract(num1, num2);
                break;
            case '3': // Multiplication
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                multiply(num1, num2);
                break;
            case '4': // Division
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                divide(num1, num2);
                break;
            case '5': // Square Root
                printf("Enter a number: ");
                scanf("%lf", &num1);
                squareRoot(num1);
                break;
            case '6': // Power
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                power(num1, num2);
                break;
            case '7': // Quit
                printf("Goodbye!\n");
                return 0;
            default: // Invalid Choice
                printf("Invalid Choice\n");
                break;
        }
        
        clearBuffer(); // Clear input buffer
        printf("\n");
    }
}