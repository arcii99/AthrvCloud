//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform addition
float addition(float x, float y) {
    return x+y;
}

// Function to perform subtraction
float subtraction(float x, float y) {
    return x-y;
}

// Function to perform multiplication
float multiplication(float x, float y) {
    return x*y;
}

// Function to perform division
float division(float x, float y) {
    if(y != 0) {
        return (float)x/y;
    } else {
        printf("ERROR: Division by zero.\n");
        return 0;
    }
}

// Function to perform modulus
int modulus(int x, int y) {
    if(y != 0) {
        return x%y;
    } else {
        printf("ERROR: Division by zero.\n");
        return 0;
    }
}

// Function to perform square root
float square_root(float x) {
    if(x >= 0) {
        return sqrt(x);
    } else {
        printf("ERROR: Square root of a negative number.\n");
        return 0;
    }
}

// Function to perform power
float power(float x, float y) {
    return pow(x,y);
}

// Function to perform factorial
int factorial(int x) {
    if(x < 0) {
        printf("ERROR: Factorial of a negative number.\n");
        return 0;
    } else {
        int fact = 1;
        for(int i=1; i<=x; i++) {
            fact *= i;
        }
        return fact;
    }
}

int main() {
    // Variable declaration
    float num1, num2, result;
    int choice;

    // Menu driven program
    do {
        printf("\n\tSCIENTIFIC CALCULATOR\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Square Root\n");
        printf("7. Power\n");
        printf("8. Factorial\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform calculations based on user choice
        switch(choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%f %f", &num1, &num2);
                result = addition(num1, num2);
                printf("Result: %f\n", result);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%f %f", &num1, &num2);
                result = subtraction(num1, num2);
                printf("Result: %f\n", result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%f %f", &num1, &num2);
                result = multiplication(num1, num2);
                printf("Result: %f\n", result);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%f %f", &num1, &num2);
                result = division(num1, num2);
                printf("Result: %f\n", result);
                break;
            case 5:
                printf("Enter two integers to find modulus: ");
                scanf("%f %f", &num1, &num2);
                result = modulus((int)num1, (int)num2);
                printf("Result: %d\n", (int)result);
                break;
            case 6:
                printf("Enter a number to find square root: ");
                scanf("%f", &num1);
                result = square_root(num1);
                printf("Result: %f\n", result);
                break;
            case 7:
                printf("Enter two numbers to find power: ");
                scanf("%f %f", &num1, &num2);
                result = power(num1, num2);
                printf("Result: %f\n", result);
                break;
            case 8:
                printf("Enter a number to find factorial: ");
                scanf("%f", &num1);
                result = factorial((int)num1);
                printf("Result: %d\n", (int)result);
                break;
            case 9:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 9);

    return 0;
}