//FormAI DATASET v1.0 Category: Fractal Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// constant declarations
const int WIDTH = 800;
const int HEIGHT = 600;
const double MIN_X = -2.0;
const double MAX_X = 2.0;
const double MIN_Y = -1.5;
const double MAX_Y = 1.5;
const int MAX_ITERATIONS = 10000;

// function declarations
int mandelbrot(double x, double y);
double map_x(int x);
double map_y(int y);

// main function
int main() {
    int i, j, k;
    int iterations;
    double x, y;
    char pixel;
    FILE *fp;

    // open the file for writing
    fp = fopen("fractal.ppm", "w");
    
    // write the image header
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    // loop over every pixel in the image
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            // map the pixel's coordinates to a complex number
            x = map_x(i);
            y = map_y(j);

            // compute the number of iterations required to escape
            iterations = mandelbrot(x, y);

            // choose a color for the pixel based on its iteration count
            if (iterations < MAX_ITERATIONS) {
                pixel = (iterations * 255) / MAX_ITERATIONS;
            } else {
                pixel = 0;
            }

            // write the color to the file
            fprintf(fp, "%c%c%c", pixel, pixel, pixel);
        }
    }

    // close the file
    fclose(fp);

    return 0;
}

// function to compute the mandelbrot set for a given complex number
int mandelbrot(double x, double y) {
    double a = 0;
    double b = 0;
    double aa, bb, ab;
    int iterations = 0;

    while (iterations < MAX_ITERATIONS && a*a + b*b < 4.0) {
        aa = a * a;
        bb = b * b;
        ab = a * b;
        a = aa - bb + x;
        b = 2 * ab + y;
        iterations++;
    }

    return iterations;
}

// function to map a pixel's x coordinate to a complex number
double map_x(int x) {
    return ((double)x / WIDTH) * (MAX_X - MIN_X) + MIN_X;
}

// function to map a pixel's y coordinate to a complex number
double map_y(int y) {
    return ((double)y / HEIGHT) * (MAX_Y - MIN_Y) + MIN_Y;
}