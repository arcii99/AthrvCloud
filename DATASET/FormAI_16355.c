//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: visionary
#include <stdio.h>
#include <math.h>

// Function to calculate addition
float add(float num1, float num2) {
    return num1 + num2;
}

// Function to calculate subtraction
float subtract(float num1, float num2) {
    return num1 - num2;
}

// Function to calculate multiplication
float multiply(float num1, float num2) {
    return num1 * num2;
}

// Function to calculate division
float divide(float num1, float num2) {
    return num1 / num2;
}

// Function to calculate factorials
int factorial(int num) {
    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate power of a number
float power(float num1, float num2) {
    return pow(num1, num2);
}

// Function to calculate square root of a number
float squareRoot(float num) {
    return sqrt(num);
}

int main() {
    int choice;
    float num1, num2;

    printf("\nWelcome to Visionary Scientific Calculator\n");

    do {
        printf("\nChoose an operation (enter the corresponding number):\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Factorial\n");
        printf("6. Power\n");
        printf("7. Square Root\n");
        printf("8. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter two numbers to add:\n");
                scanf("%f%f", &num1, &num2);
                printf("Result: %.2f\n", add(num1, num2));
                break;
            case 2:
                printf("\nEnter two numbers to subtract:\n");
                scanf("%f%f", &num1, &num2);
                printf("Result: %.2f\n", subtract(num1, num2));
                break;
            case 3:
                printf("\nEnter two numbers to multiply:\n");
                scanf("%f%f", &num1, &num2);
                printf("Result: %.2f\n", multiply(num1, num2));
                break;
            case 4:
                printf("\nEnter two numbers to divide:\n");
                scanf("%f%f", &num1, &num2);
                printf("Result: %.2f\n", divide(num1, num2));
                break;
            case 5:
                printf("\nEnter a number to calculate factorial:\n");
                scanf("%d", &num1);
                printf("Result: %d\n", factorial(num1));
                break;
            case 6:
                printf("\nEnter two numbers to calculate power:\n");
                scanf("%f%f", &num1, &num2);
                printf("Result: %.2f\n", power(num1, num2));
                break;
            case 7:
                printf("\nEnter a number to calculate square root:\n");
                scanf("%f", &num1);
                printf("Result: %.2f\n", squareRoot(num1));
                break;
            case 8:
                printf("\nThank you for using Visionary Scientific Calculator!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid number.\n");
        }
    } while (choice != 8);

    return 0;
}