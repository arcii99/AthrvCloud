//FormAI DATASET v1.0 Category: Fractal Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct for complex numbers
typedef struct {
    double real;
    double imag;
} complex;

// Function that calculates the square of a complex number
complex complex_square(complex c) {
    complex result;
    result.real = c.real * c.real - c.imag * c.imag;
    result.imag = 2 * c.real * c.imag;
    return result;
}

// Function that adds two complex numbers
complex complex_add(complex c1, complex c2) {
    complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Recursive function that generates the fractal
void generate_fractal(complex c, int depth, int max_depth) {
    // If we have reached the maximum depth, we print the current complex number
    if (depth == max_depth) {
        printf("%.6lf %.6lf\n", c.real, c.imag);
        return;
    }
    
    // Calculate the next complex number in the sequence
    complex c_next = complex_add(complex_square(c), c);
    
    // Generate fractal for the next complex number
    generate_fractal(c_next, depth + 1, max_depth);
}

int main() {
    // Define the starting complex number
    complex c_start;
    c_start.real = -2.0;
    c_start.imag = -2.0;
    
    // Define the step size for the real and imaginary parts
    double step = 0.005;
    
    // Define the maximum depth for the fractal
    int max_depth = 50;
    
    // Loop over the real and imaginary parts and generate the fractal for each point
    for (double real = c_start.real; real <= 2.0; real += step) {
        for (double imag = c_start.imag; imag <= 2.0; imag += step) {
            complex c;
            c.real = real;
            c.imag = imag;
            generate_fractal(c, 0, max_depth);
        }
    }
    
    return 0;
}