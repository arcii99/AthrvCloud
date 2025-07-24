//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Constants for the fractal generation */
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
#define MAX_ITERATIONS 1000
#define SCALE_FACTOR 0.02

/* Function to check if a point is in the Mandelbrot set */
int isInMandelbrotSet(double x, double y) {
    double real = x;
    double imag = y;
    int iterations = 0;

    while (real * real + imag * imag <= 4.0 && iterations < MAX_ITERATIONS) {
        double temp = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = temp;
        iterations++;
    }

    if (iterations == MAX_ITERATIONS) {
        return 1;
    } else {
        return 0;
    }
}

/* Function to scale the coordinate system */
double scale(int point, int screen, double min, double max) {
    return (1.0 * point / (screen - 1)) * (max - min) + min;
}

/* Main function to generate the fractal */
int main() {
    /* Variables for scaling and generating the fractal */
    double x_min = -2.0;
    double x_max = 1.0;
    double y_min = -1.0;
    double y_max = 1.0;
    double x, y;
    int i, j;

    /* Loop through all the points and check if each one is in the Mandelbrot set */
    for (i = 0; i < WINDOW_HEIGHT; i++) {
        for (j = 0; j < WINDOW_WIDTH; j++) {
            /* Scale the current point in the coordinate system */
            x = scale(j, WINDOW_WIDTH, x_min, x_max);
            y = scale(i, WINDOW_HEIGHT, y_min, y_max);

            /* Check if the current point is in the Mandelbrot set */
            int is_mandelbrot = isInMandelbrotSet(x, y);

            /* Print out a character based on whether or not the point is in the set */
            if (is_mandelbrot) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}