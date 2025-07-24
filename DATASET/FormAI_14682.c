//FormAI DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>

// Function to add two numbers
int add(int a, int b) {
    int sum = a + b;
    return sum;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    int result = a - b;
    return result;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    int product = a * b;
    return product;
}

// Function to divide two numbers
float divide(int a, int b) {
    float quotient = (float)a / (float)b;
    return quotient;
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int sum = add(a, b);
    printf("Sum = %d\n", sum);
    int difference = subtract(a, b);
    printf("Difference = %d\n", difference);
    int product = multiply(a, b);
    printf("Product = %d\n", product);
    float quotient = divide(a, b);
    printf("Quotient = %f\n", quotient);
    return 0;
}