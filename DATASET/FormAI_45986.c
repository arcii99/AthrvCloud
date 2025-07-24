//FormAI DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>

// initialize global variables
int num1, num2, operation;

// function to perform addition
void addNumbers(int x, int y) {
    int sum = x + y;
    printf("Sum of %d and %d is %d\n", x, y, sum);
}

// function to perform subtraction
void subtractNumbers(int x, int y) {
    int diff = x - y;
    printf("Difference between %d and %d is %d\n", x, y, diff);
}

// function to perform multiplication
void multiplyNumbers(int x, int y) {
    int prod = x * y;
    printf("Product of %d and %d is %d\n", x, y, prod);
}

int main() {
    printf("Welcome to the calculator program!\n");
    printf("Enter two numbers separated by a space: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter the operation you want to perform:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
    scanf("%d", &operation);

    switch (operation) {
        case 1:
            addNumbers(num1, num2);
            break;
        case 2:
            subtractNumbers(num1, num2);
            break;
        case 3:
            multiplyNumbers(num1, num2);
            break;
        default:
            printf("Invalid operation selected. Please try again.");
    }
    return 0;
}