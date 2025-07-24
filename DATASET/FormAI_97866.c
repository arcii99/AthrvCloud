//FormAI DATASET v1.0 Category: Fractal Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define struct to store complex numbers
typedef struct {
    double real;
    double imag;
} complex;

// define constants
#define WIDTH 80
#define HEIGHT 45
#define MAX_ITERATIONS 50
#define ZOOM 1.5

// function to calculate the Mandelbrot set for a given complex number
int calculateMandelbrot(complex c) {
    complex z = {0,0};
    int iterations = 0;
    while (z.real*z.real + z.imag*z.imag <= 4 && iterations < MAX_ITERATIONS) {
        double temp = z.real;
        z.real = z.real*z.real - z.imag*z.imag + c.real;
        z.imag = 2*temp*z.imag + c.imag;
        iterations++;
    }
    return iterations;
}

int main() {
    // initialize variables
    complex center = {-0.7,0};
    double range = 3;
    double delta = range/WIDTH;
    int i, j;

    // iterate over pixels
    for (j=0; j<HEIGHT; j++) {
        for (i=0; i<WIDTH; i++) {
            // calculate complex number for current pixel
            complex c = {center.real - range/2 + i*delta, center.imag - range/2 + j*delta};
            
            // calculate Mandelbrot value for current complex number
            int value = calculateMandelbrot(c);
            
            // normalize value to be between 0 and 1
            double normalized = (double)value/MAX_ITERATIONS;
            
            // print character based on normalized value
            if (normalized < 0.1) {
                printf(",");
            } else if (normalized < 0.2) {
                printf(".");
            } else if (normalized < 0.3) {
                printf("-");
            } else if (normalized < 0.4) {
                printf("+");
            } else if (normalized < 0.5) {
                printf("=");
            } else if (normalized < 0.6) {
                printf("*");
            } else if (normalized < 0.7) {
                printf("#");
            } else if (normalized < 0.8) {
                printf("%");
            } else if (normalized < 0.9) {
                printf("@");
            } else {
                printf("O");
            }
        }
        printf("\n");
    }
    
    return 0;
}