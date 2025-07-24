//FormAI DATASET v1.0 Category: Fractal Generation ; Style: interoperable
#include <stdio.h>

// Constants
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define MAX_ITERATIONS 100

// Struct for holding complex numbers
typedef struct {
    double real;
    double imag;
} Complex;

// Function for computing the absolute value of a complex number
double cabs(Complex c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

// Function for computing the square of a complex number
Complex csquare(Complex c) {
    Complex result;
    result.real = c.real * c.real - c.imag * c.imag;
    result.imag = 2 * c.real * c.imag;
    return result;
}

// Function for computing the Mandelbrot fractal
int mandelbrot(int x, int y) {
    // Convert pixel coordinates to complex number
    Complex c;
    c.real = (double)x / SCREEN_WIDTH * 4 - 2;
    c.imag = (double)y / SCREEN_HEIGHT * 4 - 2;

    // Initialize z to 0
    Complex z = {0, 0};

    // Iterate until |z| > 2 or maximum iterations is reached
    int iterations = 0;
    while (cabs(z) < 2 && iterations < MAX_ITERATIONS) {
        z = csquare(z);
        z.real += c.real;
        z.imag += c.imag;
        iterations++;
    }

    // Map iterations to color
    if (iterations == MAX_ITERATIONS) {
        return 0; // Black
    } else {
        return iterations % 8 + 1; // Rainbow colors
    }
}

// Main function
int main() {
    // Create buffer for holding pixel data
    char buffer[SCREEN_WIDTH * SCREEN_HEIGHT];

    // Compute Mandelbrot fractal and write pixel data to buffer
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            buffer[y * SCREEN_WIDTH + x] = mandelbrot(x, y);
        }
    }

    // Output pixel data as PGM image
    printf("P2\n%d %d\n9\n", SCREEN_WIDTH, SCREEN_HEIGHT);
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            printf("%d ", buffer[y * SCREEN_WIDTH + x]);
        }
        printf("\n");
    }

    return 0;
}