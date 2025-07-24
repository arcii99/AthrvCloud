//FormAI DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>

// Define a Complex Struct 
struct complex {
    float real;
    float imag;
};

typedef struct complex Complex;

// Define Add Function
Complex add(Complex a, Complex b) {
    
    Complex result;
    
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    
    return result;
}

// Define Subtract Function
Complex subtract(Complex a, Complex b) {
    
    Complex result;
    
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    
    return result;
}

// Define Multiply Function
Complex multiply(Complex a, Complex b) {
    
    Complex result;
    
    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) + (a.imag * b.real);
    
    return result;
}

// Define Divide Function
Complex divide(Complex a, Complex b) {
    
    Complex result;
    
    result.real = ((a.real * b.real) + (a.imag * b.imag)) / ((b.real * b.real) + (b.imag * b.imag));
    result.imag = ((a.imag * b.real) - (a.real * b.imag)) / ((b.real * b.real) + (b.imag * b.imag));
    
    return result;
}

int main() {
    // Define two input Complex numbers
    Complex a = {1, 2};
    Complex b = {3, 4};
    
    printf("Arithmetic Operations on Complex Numbers \n\n");
    printf("Complex Number 1: %.2f + %.2fi \n", a.real, a.imag);
    printf("Complex Number 2: %.2f + %.2fi \n\n", b.real, b.imag);
    
    // Add the two numbers
    printf("Addition: (%.2f + %.2fi) + (%.2f + %.2fi) = ", a.real, a.imag, b.real, b.imag);
    Complex sum = add(a, b);
    printf("%.2f + %.2fi \n", sum.real, sum.imag);
    
    // Subtract the two numbers
    printf("Subtraction: (%.2f + %.2fi) - (%.2f + %.2fi) = ", a.real, a.imag, b.real, b.imag);
    Complex difference = subtract(a, b);
    printf("%.2f + %.2fi \n", difference.real, difference.imag);
    
    // Multiply the two numbers
    printf("Multiplication: (%.2f + %.2fi) * (%.2f + %.2fi) = ", a.real, a.imag, b.real, b.imag);
    Complex product = multiply(a, b);
    printf("%.2f + %.2fi \n", product.real, product.imag);
    
    // Divide the two numbers
    printf("Division: (%.2f + %.2fi) / (%.2f + %.2fi) = ", a.real, a.imag, b.real, b.imag);
    Complex quotient = divide(a, b);
    printf("%.2f + %.2fi \n", quotient.real, quotient.imag);
    
    return 0;
}