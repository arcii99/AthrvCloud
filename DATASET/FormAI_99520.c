//FormAI DATASET v1.0 Category: Fractal Generation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants for the fractal generation
#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000

// A structure to store the complex numbers
typedef struct {
    double real;
    double imag;
} complex;

// Function to calculate the mandelbrot set
int mandelbrot(complex c) {
    complex z = {0, 0};
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        if (sqrt(z.real * z.real + z.imag * z.imag) >= 2.0) {
            return i;
        }
        complex temp = {z.real*z.real - z.imag*z.imag, 2.0*z.real*z.imag};
        z.real = temp.real + c.real;
        z.imag = temp.imag + c.imag;
    }
    return 0;
}

// Function to normalize the value in the range 0-255
int normalize(double value) {
    return (int)((value / (double)MAX_ITERATIONS) * 255);
}

int main() {
    // Initialize the image array
    unsigned char image[WIDTH*HEIGHT];

    // Generate the fractal
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            complex c = {((double)x - WIDTH/2.0) * 4.0 / (double)WIDTH,
                         ((double)y - HEIGHT/2.0) * 4.0 / (double)WIDTH};
            int iterations = mandelbrot(c);
            image[y*WIDTH+x] = normalize(iterations);
        }
    }

    // Output the image
    printf("P5\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(unsigned char), WIDTH*HEIGHT, stdout);

    return 0;
}