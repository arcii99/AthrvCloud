//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Utility function to clear the screen
void clearScreen() {
    system("clear");
}

// Function to display the calculator menu
void displayMenu() {
    printf("\n------------------");
    printf("\n Scientific Calculator");
    printf("\n------------------");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Square root");
    printf("\n6. Exponential");
    printf("\n7. Sine");
    printf("\n8. Cosine");
    printf("\n9. Tangent");
    printf("\n10. Logarithm");
    printf("\nEnter your choice: ");
}

// Function to perform addition
void addition() {
    clearScreen();
    double x, y, result;
    printf("\nEnter the first number: ");
    scanf("%lf", &x);
    printf("Enter the second number: ");
    scanf("%lf", &y);
    result = x + y;
    printf("\nResult: %lf\n", result);
}

// Function to perform subtraction
void subtraction() {
    clearScreen();
    double x, y, result;
    printf("\nEnter the first number: ");
    scanf("%lf", &x);
    printf("Enter the second number: ");
    scanf("%lf", &y);
    result = x - y;
    printf("\nResult: %lf\n", result);
}

// Function to perform multiplication
void multiplication() {
    clearScreen();
    double x, y, result;
    printf("\nEnter the first number: ");
    scanf("%lf", &x);
    printf("Enter the second number: ");
    scanf("%lf", &y);
    result = x * y;
    printf("\nResult: %lf\n", result);
}

// Function to perform division
void division() {
    clearScreen();
    double x, y, result;
    printf("\nEnter the first number: ");
    scanf("%lf", &x);
    printf("Enter the second number: ");
    scanf("%lf", &y);
    // Check for divide by zero
    if (y == 0) {
        printf("\nDivide by zero error!\n");
        return;
    }
    result = x / y;
    printf("\nResult: %lf\n", result);
}

// Function to perform square root
void squareRoot() {
    clearScreen();
    double x, result;
    printf("\nEnter the number: ");
    scanf("%lf", &x);
    // Check for negative number
    if (x < 0) {
        printf("\nInvalid input!\n");
        return;
    }
    result = sqrt(x);
    printf("\nResult: %lf\n", result);
}

// Function to perform exponential
void exponential() {
    clearScreen();
    double x, result;
    printf("\nEnter the number: ");
    scanf("%lf", &x);
    result = exp(x);
    printf("\nResult: %lf\n", result);
}

// Function to perform sine
void sine() {
    clearScreen();
    double x, result;
    printf("\nEnter the angle (in radians): ");
    scanf("%lf", &x);
    result = sin(x);
    printf("\nResult: %lf\n", result);
}

// Function to perform cosine
void cosine() {
    clearScreen();
    double x, result;
    printf("\nEnter the angle (in radians): ");
    scanf("%lf", &x);
    result = cos(x);
    printf("\nResult: %lf\n", result);
}

// Function to perform tangent
void tangent() {
    clearScreen();
    double x, result;
    printf("\nEnter the angle (in radians): ");
    scanf("%lf", &x);
    result = tan(x);
    printf("\nResult: %lf\n", result);
}

// Function to perform logarithm
void logarithm() {
    clearScreen();
    double x, result;
    printf("\nEnter the number: ");
    scanf("%lf", &x);
    // Check for negative number
    if (x < 0) {
        printf("\nInvalid input!\n");
        return;
    }
    result = log(x);
    printf("\nResult: %lf\n", result);
}

int main() {
    clearScreen();
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                squareRoot();
                break;
            case 6:
                exponential();
                break;
            case 7:
                sine();
                break;
            case 8:
                cosine();
                break;
            case 9:
                tangent();
                break;
            case 10:
                logarithm();
                break;
            default:
                clearScreen();
                printf("\nInvalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}