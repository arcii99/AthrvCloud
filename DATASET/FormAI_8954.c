//FormAI DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>

// Function to add two numbers
int add(int num1, int num2) {
    return num1 + num2;
}

// Function to subtract two numbers
int subtract(int num1, int num2) {
    return num1 - num2;
}

// Function to multiply two numbers
int multiply(int num1, int num2) {
    return num1 * num2;
}

// Function to divide two numbers
float divide(int num1, int num2) {
    return (float)num1 / (float)num2;
}

int main() {
    int num1 = 5, num2 = 10;
    printf("Numbers before arithmetic operations: num1=%d, num2=%d\n", num1, num2);

    // Adding two numbers
    int sum = add(num1, num2);
    printf("Sum of %d and %d is %d\n", num1, num2, sum);

    // Subtracting two numbers
    int difference = subtract(num1, num2);
    printf("Difference between %d and %d is %d\n", num1, num2, difference);

    // Multiplying two numbers
    int product = multiply(num1, num2);
    printf("Product of %d and %d is %d\n", num1, num2, product);

    // Dividing two numbers
    float quotient = divide(num2, num1);
    printf("Quotient of %d divided by %d is %.2f\n", num2, num1, quotient);

    return 0;
}