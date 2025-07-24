//FormAI DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers
float divide(int a, int b) {
    return (float)a / (float)b;
}

int main() {
    int a, b;
    char operator;

    printf("Enter an expression with two numbers and an operator (+, -, *, /): ");
    scanf("%d %c %d", &a, &operator, &b);

    switch(operator) {
        case '+':
            printf("%d + %d = %d\n", a, b, add(a, b));
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, subtract(a, b));
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, multiply(a, b));
            break;
        case '/':
            printf("%d / %d = %0.2f\n", a, b, divide(a, b));
            break;
        default:
            printf("Invalid operator\n");
    }

    return 0;
}