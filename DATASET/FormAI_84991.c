//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define maximum complexity
#define MAX_DEPTH 20

// Define complex number struct
typedef struct {
    double r;   // real part
    double i;   // imaginary part
} complex;

// Define bounds of the fractal
const double MIN_X = -2.5;
const double MAX_X = 1.5;
const double MIN_Y = -2.0;
const double MAX_Y = 2.0;

// Define constants for Julia Set (can be changed for different fractals)
const complex C = {-0.4, 0.6};
const double BAILOUT = 4.0;

// Function to calculate the squared magnitude of a complex number
double complex_magnitude_squared(complex z) {
    return z.r * z.r + z.i * z.i;
}

// Function to perform a complex multiplication
complex complex_multiply(complex a, complex b) {
    complex result;
    result.r = a.r * b.r - a.i * b.i;
    result.i = a.r * b.i + a.i * b.r;
    return result;
}

// Function to perform a complex addition
complex complex_add(complex a, complex b) {
    complex result;
    result.r = a.r + b.r;
    result.i = a.i + b.i;
    return result;
}

// Function to perform a complex power operation
complex complex_power(complex z, int power) {
    complex result = {1.0, 0.0};
    for (int i = 0; i < power; i++) {
        result = complex_multiply(result, z);
    }
    return result;
}

// Function to perform the fractal calculation for a single point
int fractal_point(double x, double y) {
    complex z = {x, y};
    for (int i = 0; i < MAX_DEPTH; i++) {
        z = complex_add(complex_power(z, 2), C);
        if (complex_magnitude_squared(z) > BAILOUT) {
            return i;
        }
    }
    return MAX_DEPTH;
}

// Main function to generate and print the fractal image
int main() {
    // Define constants for image size and step size
    const int WIDTH = 80;
    const int HEIGHT = 40;
    const double STEP_X = (MAX_X - MIN_X) / (double) WIDTH;
    const double STEP_Y = (MAX_Y - MIN_Y) / (double) HEIGHT;

    // Loop through each point and calculate the fractal value
    for (double y = MAX_Y; y >= MIN_Y; y -= STEP_Y) {
        for (double x = MIN_X; x <= MAX_X; x += STEP_X) {
            int value = fractal_point(x, y);

            // Print the corresponding character based on the fractal value
            if (value == MAX_DEPTH) {
                printf(".");
            } else if (value == MAX_DEPTH - 1) {
                printf("*");
            } else if (value > MAX_DEPTH / 2) {
                printf("+");
            } else if (value > MAX_DEPTH / 3) {
                printf("x");
            } else if (value > MAX_DEPTH / 4) {
                printf("|");
            } else {
                printf("=");
            }
        }
        printf("\n");
    }

    // Return success
    return EXIT_SUCCESS;
}