//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

// Function to print the calculator menu
void printMenu() {
    printf("\nCalculator Menu:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Power (^)\n");
    printf("6. Square root (√)\n");
    printf("7. Logarithm (log)\n");
    printf("8. Sine (sin)\n");
    printf("9. Cosine (cos)\n");
    printf("10. Tangent (tan)\n");
    printf("11. Exit\n");
}

// Function to add two numbers
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to subtract two numbers
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to multiply two numbers
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to divide two numbers
double divide(double num1, double num2) {
    return num1 / num2;
}

// Function to calculate power of a number
double power(double num1, double num2) {
    return pow(num1, num2);
}

// Function to calculate square root of a number
double squareRoot(double num) {
    return sqrt(num);
}

// Function to calculate logarithm of a number
double logarithm(double num) {
    return log(num);
}

// Function to calculate sine of a number
double sine(double num) {
    return sin(num);
}

// Function to calculate cosine of a number
double cosine(double num) {
    return cos(num);
}

// Function to calculate tangent of a number
double tangent(double num) {
    return tan(num);
}

int main() {
    int choice;
    double num1, num2, result;
    
    printf("Welcome to the Ultracalculator!\n");

    do {
        // Print the calculator menu and get the user's choice
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Perform the appropriate operation based on the user's choice
        switch(choice) {
            case 1: // Addition
                printf("Enter number 1: ");
                scanf("%lf", &num1);
                printf("Enter number 2: ");
                scanf("%lf", &num2);
                result = add(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 2: // Subtraction
                printf("Enter number 1: ");
                scanf("%lf", &num1);
                printf("Enter number 2: ");
                scanf("%lf", &num2);
                result = subtract(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 3: // Multiplication
                printf("Enter number 1: ");
                scanf("%lf", &num1);
                printf("Enter number 2: ");
                scanf("%lf", &num2);
                result = multiply(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 4: // Division
                printf("Enter number 1: ");
                scanf("%lf", &num1);
                printf("Enter number 2: ");
                scanf("%lf", &num2);
                result = divide(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 5: // Power
                printf("Enter number 1: ");
                scanf("%lf", &num1);
                printf("Enter number 2: ");
                scanf("%lf", &num2);
                result = power(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 6: // Square root
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                printf("Result: %lf\n", result);
                break;
            case 7: // Logarithm
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = logarithm(num1);
                printf("Result: %lf\n", result);
                break;
            case 8: // Sine
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("Result: %lf\n", result);
                break;
            case 9: // Cosine
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("Result: %lf\n", result);
                break;
            case 10: // Tangent
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = tangent(num1);
                printf("Result: %lf\n", result);
                break;
            case 11: // Exit
                printf("Thank you for using the Ultracalculator! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    } while (choice != 11);

    return 0;
}