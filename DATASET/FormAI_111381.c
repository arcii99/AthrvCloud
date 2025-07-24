//FormAI DATASET v1.0 Category: Fractal Generation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_ITERATIONS 1000
#define MAX_PIXELS 1000
#define DEFAULT_COLOR "  "

// Struct to represent a complex number
typedef struct {
    double real;
    double imag;
} Complex;

// Generate a random complex number within the specified ranges
Complex generateRandomComplex(double x_min, double x_max, double y_min, double y_max) {
    Complex c;
    c.real = (double) (rand() / (double) RAND_MAX) * (x_max - x_min) + x_min;
    c.imag = (double) (rand() / (double) RAND_MAX) * (y_max - y_min) + y_min;
    return c;
}

// Check if a complex number is in the Mandelbrot set
bool isInMandelbrotSet(Complex c) {
    int iterations = 0;
    Complex z = {0, 0};
    while (iterations < MAX_ITERATIONS) {
        Complex z_next;
        z_next.real = z.real * z.real - z.imag * z.imag + c.real;
        z_next.imag = 2 * z.real * z.imag + c.imag;
        if (z_next.real * z_next.real + z_next.imag * z_next.imag > 4) {
            return false; // The point is outside of the set
        }
        z = z_next;
        iterations++;
    }
    return true; // The point is inside the set
}

// Print the Mandelbrot set in ASCII to the console
void printMandelbrotSet(double x_min, double x_max, double y_min, double y_max) {
    srand(time(NULL)); // Seed the random number generator
    double dx = (x_max - x_min) / MAX_PIXELS;
    double dy = (y_max - y_min) / MAX_PIXELS;

    for (int i = 0; i < MAX_PIXELS; i++) {
        for (int j = 0; j < MAX_PIXELS; j++) {
            double x = x_min + i * dx;
            double y = y_min + j * dy;
            Complex c = {x, y};
            if (isInMandelbrotSet(c)) {
                printf(DEFAULT_COLOR); // Print default color for Mandelbrot set
            } else {
                printf(DEFAULT_COLOR); // Print default color for points outside Mandelbrot set
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    double x_min = -2.5; // Minimum x value on the complex plane
    double x_max = 1; // Maximum x value on the complex plane
    double y_min = -1; // Minimum y value on the complex plane
    double y_max = 1; // Maximum y value on the complex plane

    printMandelbrotSet(x_min, x_max, y_min, y_max);
    return 0;
}