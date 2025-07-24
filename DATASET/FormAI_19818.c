//FormAI DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>

// Function to calculate absolute value of a number
float absoluteValue(float num) {
    if (num < 0) {
        num *= -1;
    }
    return num;
}

// Function to find the square root of a number
float squareRoot(float num) {
    float guess = 1.0;
    float result = 0.0;
    float precision = 0.00001;
    
    while (absoluteValue(guess - result) > precision) {
        result = num / guess;
        guess = (guess + result) / 2;
    }
    
    return guess;
}

// Function to find the factorial of a number
int factorial(int num) {
    int fact = 1;
    for (int i = 2; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Function to add two complex numbers
struct Complex {
    float real, imag;
};

struct Complex addComplex(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Main function
int main() {
    float num1 = 32.0;
    float num2 = 12.0;
    printf("The square root of %.2f is %.2f\n", num1, squareRoot(num1));
    printf("The factorial of 5 is %d\n", factorial(5));
    
    struct Complex c1, c2, result;
    c1.real = 2.5;
    c1.imag = 3.5;
    c2.real = 1.0;
    c2.imag = 2.0;
    result = addComplex(c1, c2);
    printf("The sum of %.2f + %.2fi and %.2f + %.2fi is %.2f + %.2fi\n", c1.real, c1.imag, c2.real, c2.imag, result.real, result.imag);
    
    return 0;
}