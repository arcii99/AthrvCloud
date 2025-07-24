//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function declarations for all calculator operations
float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);
float power(float num1, float num2);
float square_root(float num);

int main() {
    int choice;
    float num1, num2, result;
    char ch;
    do {
        printf("Choose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square Root\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%f %f", &num1, &num2);
                result = add(num1, num2);
                printf("%.2f + %.2f = %.2f\n\n", num1, num2, result);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%f %f", &num1, &num2);
                result = subtract(num1, num2);
                printf("%.2f - %.2f = %.2f\n\n", num1, num2, result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%f %f", &num1, &num2);
                result = multiply(num1, num2);
                printf("%.2f x %.2f = %.2f\n\n", num1, num2, result);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%f %f", &num1, &num2);
                if (num2 == 0) {
                    printf("Error! Division by zero.\n\n");
                } else {
                    result = divide(num1, num2);
                    printf("%.2f / %.2f = %.2f\n\n", num1, num2, result);
                }
                break;
            case 5:
                printf("Enter a number and its exponent: ");
                scanf("%f %f", &num1, &num2);
                result = power(num1, num2);
                printf("%.2f ^ %.2f = %.2f\n\n", num1, num2, result);
                break;
            case 6:
                printf("Enter a number to find its square root: ");
                scanf("%f", &num1);
                if (num1 < 0) {
                    printf("Error! Cannot find square root of negative numbers.\n\n");
                } else {
                    result = square_root(num1);
                    printf("Square root of %.2f = %.2f\n\n", num1, result);
                }
                break;
            default:
                printf("Invalid input.\n\n");
        }
        printf("Do you want to perform another operation? (Y/N) ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}

//Function to perform addition
float add(float num1, float num2) {
    return num1 + num2;
}

//Function to perform subtraction
float subtract(float num1, float num2) {
    return num1 - num2;
}

//Function to perform multiplication
float multiply(float num1, float num2) {
    return num1 * num2;
}

//Function to perform division
float divide(float num1, float num2) {
    return num1 / num2;
}

//Function to perform power operation
float power(float num1, float num2) {
    return pow(num1, num2);
}

//Function to find square root
float square_root(float num) {
    return sqrt(num);
}