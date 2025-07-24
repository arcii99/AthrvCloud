//FormAI DATASET v1.0 Category: Fractal Generation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_DEPTH 1000

// Defining a data type for complex numbers
typedef struct {
    double real;
    double imag;
} complex;

// Function to calculate the absolute value of a complex number
double abs_complex(complex c) {
    return sqrt(pow(c.real, 2) + pow(c.imag, 2));
}

// Function to perform the Mandelbrot iteration
int mandelbrot(complex c, int max_iter) {
    int n = 0;
    complex z = {0, 0};
    while (n < max_iter && abs_complex(z) < 4) {
        complex tmp;
        tmp.real = pow(z.real, 2) - pow(z.imag, 2) + c.real;
        tmp.imag = 2 * z.real * z.imag + c.imag;
        z = tmp;
        n++;
    }
    return n;
}

// Main function
int main() {

    // Initializing image buffer
    int image[WIDTH][HEIGHT];

    // Defining viewport and scaling factor
    complex min = {-2, -2};
    complex max = {2, 2};
    double dx = (max.real - min.real) / WIDTH;
    double dy = (max.imag - min.imag) / HEIGHT;

    // Loop over every pixel and calculate its color
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            complex c = {min.real + x * dx, min.imag + y * dy};
            int depth = mandelbrot(c, MAX_DEPTH);
            double color = depth == MAX_DEPTH ? 0 : log(depth) / log(MAX_DEPTH);
            image[x][y] = color * 255;
        }
    }

    // Writing image to file
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6 %d %d 255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fputc(image[x][y], fp);
            fputc(image[x][y], fp);
            fputc(image[x][y], fp);
        }
    }
    fclose(fp);

    return 0;
}