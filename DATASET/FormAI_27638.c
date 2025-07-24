//FormAI DATASET v1.0 Category: Scientific ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct for complex numbers
struct Complex {
    double real;
    double imag;
};

// Declare functions to perform complex arithmetic
struct Complex add(struct Complex num1, struct Complex num2);
struct Complex subtract(struct Complex num1, struct Complex num2);
struct Complex multiply(struct Complex num1, struct Complex num2);
struct Complex divide(struct Complex num1, struct Complex num2);
double modulus(struct Complex num);
struct Complex conjugate(struct Complex num);

int main() {
    // Create two complex numbers
    struct Complex num1 = {4, 2};
    struct Complex num2 = {2, -3};

    // Perform arithmetic operations on the numbers
    struct Complex sum = add(num1, num2);
    struct Complex difference = subtract(num1, num2);
    struct Complex product = multiply(num1, num2);
    struct Complex quotient = divide(num1, num2);

    // Print out the results
    printf("The sum of the complex numbers is: %.2f + %.2fi\n", sum.real, sum.imag);
    printf("The difference of the complex numbers is: %.2f + %.2fi\n", difference.real, difference.imag);
    printf("The product of the complex numbers is: %.2f + %.2fi\n", product.real, product.imag);
    printf("The quotient of the complex numbers is: %.2f + %.2fi\n", quotient.real, quotient.imag);
    printf("The modulus of num1 is: %.2f\n", modulus(num1));
    printf("The conjugate of num2 is: %.2f + %.2fi\n", conjugate(num2).real, conjugate(num2).imag);

    return 0;
}

// Function to add two complex numbers
struct Complex add(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

// Function to subtract two complex numbers
struct Complex subtract(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiply(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real * num2.real - num1.imag * num2.imag;
    result.imag = num1.real * num2.imag + num1.imag * num2.real;
    return result;
}

// Function to divide two complex numbers
struct Complex divide(struct Complex num1, struct Complex num2) {
    struct Complex result;
    double denominator = pow(num2.real, 2) + pow(num2.imag, 2);
    result.real = (num1.real * num2.real + num1.imag * num2.imag) / denominator;
    result.imag = (num1.imag * num2.real - num1.real * num2.imag) / denominator;
    return result;
}

// Function to find the modulus of a complex number
double modulus(struct Complex num) {
    return sqrt(pow(num.real, 2) + pow(num.imag, 2));
}

// Function to find the conjugate of a complex number
struct Complex conjugate(struct Complex num) {
    struct Complex result;
    result.real = num.real;
    result.imag = -num.imag;
    return result;
}