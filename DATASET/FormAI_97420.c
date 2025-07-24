//FormAI DATASET v1.0 Category: Fractal Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000
#define BAIL_OUT 2
#define MIN_X -2.0
#define MAX_X 2.0
#define MIN_Y -1.5
#define MAX_Y 1.5

typedef struct Complex {
    double real;
    double imaginary;
} Complex;

// Function to calculate complex modulus
double modulus(Complex c) {
    return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}

// Function to calculate square of a complex number
Complex square(Complex c) {
    Complex result;
    result.real = c.real * c.real - c.imaginary * c.imaginary;
    result.imaginary = 2 * c.real * c.imaginary;
    return result;
}

// Function to calculate the iteration count using Mandelbrot formula
int calculateIterations(Complex c) {
    Complex z = {0, 0};
    int iterations = 0;
    while (modulus(z) < BAIL_OUT && iterations < MAX_ITERATIONS) {
        z = square(z);
        z.real += c.real;
        z.imaginary += c.imaginary;
        iterations++;
    }
    return iterations;
}

int main() {
    // Initializing variables
    int i, j, iterations;
    Complex c;
    FILE *fp;
    char *filename = "fractal.ppm";

    // Opening file for output
    fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: Unable to open file for writing");
        return 1;
    }

    // Writing header information to file in ppm format
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    // Looping over all pixels in image
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            // Calculating complex number for current pixel
            c.real = MIN_X + ((double)i / (double)WIDTH) * (MAX_X - MIN_X);
            c.imaginary = MIN_Y + ((double)j / (double)HEIGHT) * (MAX_Y - MIN_Y);

            // Calculating number of iterations for current complex number
            iterations = calculateIterations(c);

            // Assigning color based on number of iterations
            if (iterations == MAX_ITERATIONS) {
                fputc(0, fp);
                fputc(0, fp);
                fputc(0, fp);
            } else {
                // Scaling color based on number of iterations
                double color = ((double)iterations / (double)MAX_ITERATIONS) * 255;
                fputc((int)color, fp);
                fputc((int)color, fp);
                fputc((int)color, fp);
            }
        }
    }

    // Closing file
    fclose(fp);

    return 0;
}