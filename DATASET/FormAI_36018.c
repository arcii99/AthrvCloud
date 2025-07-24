//FormAI DATASET v1.0 Category: Fractal Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define MAX_ITER 1000

typedef struct _ComplexNumber {
    double real;
    double imag;
} ComplexNumber;

// Define the ComplexNumber struct

ComplexNumber newComplexNumber(double realPart, double imaginaryPart) {
    // Helper method to create a new ComplexNumber
    ComplexNumber num;
    num.real = realPart;
    num.imag = imaginaryPart;
    return num;
}

ComplexNumber complexAdd(ComplexNumber num1, ComplexNumber num2) {
    // Helper method to calculate the sum of two ComplexNumbers
    ComplexNumber result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

ComplexNumber complexMul(ComplexNumber num1, ComplexNumber num2) {
    // Helper method to calculate the product of two ComplexNumbers
    ComplexNumber result;
    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    return result;
}

int juliaSet(ComplexNumber c, ComplexNumber z) {
    // Calculate if a point on the complex plane is in the Julia Set
    int iterations = 0;
    ComplexNumber num;
    while(iterations < MAX_ITER) {
        num = complexAdd(complexMul(z, z), c);
        if(fabs(num.real) > 2 || fabs(num.imag) > 2) {
            return iterations;
        }
        z = num;
        iterations++;
    }
    return -1;
}

void printJuliaSet(double cReal, double cImag, int width, int height) {
    // Print the Julia Set to the console
    ComplexNumber c = newComplexNumber(cReal, cImag);
    ComplexNumber z;
    double x, y;
    int iterations;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            x = ((double)j / (double)width) * 4 - 2;
            y = ((double)i / (double)height) * 4 - 2;
            z = newComplexNumber(x, y);
            iterations = juliaSet(c, z);
            if(iterations >= 0) {
                printf("%d", iterations % 10);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    printJuliaSet(0.285, 0.01, 40, 20);
    return 0;
}