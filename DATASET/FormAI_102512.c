//FormAI DATASET v1.0 Category: Fractal Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>


// function to generate Mandelbrot set
void generateMandelbrotSet(FILE* fp, double x_min, double x_max, double y_min, double y_max, int max_iterations, int width, int height) {
    double x, y, x_scaled, y_scaled, x_step, y_step, bailout_squared;
    int i, j, k, iterations;
    complex c, z, z_squared;

    // calculate the step size for x and y
    x_step = (x_max - x_min) / (double)width;
    y_step = (y_max - y_min) / (double)height;

    // set the bailout squared value
    bailout_squared = (double)max_iterations * (double)max_iterations;

    // loop through all the x and y values
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            // calculate the scaled x and y values
            x_scaled = x_min + ((double)i * x_step);
            y_scaled = y_min + ((double)j * y_step);

            // set the initial complex number
            c = x_scaled + (y_scaled * I);
            z = c;
            z_squared = z * z;
            iterations = 0;

            // loop until the complex number diverges or max_iterations is reached
            while ((creal(z_squared) + cimag(z_squared)) < bailout_squared && iterations < max_iterations) {
                z = z_squared + c;
                z_squared = z * z;
                iterations++;
            }

            // get the color value for the pixel
            k = (iterations == max_iterations) ? 0 : iterations % 255;
            fprintf(fp, "%d %d %d\n", k, k, k);
        }
    }
}

// driver function
int main() {
    FILE* fp;
    fp = fopen("mandelbrot.ppm", "w+");

    // set the size, scale and number of iterations
    int WIDTH = 800;
    int HEIGHT = 600;
    double X_MIN = -2.0;
    double X_MAX = 1.0;
    double Y_MIN = -1.5;
    double Y_MAX = 1.5;
    int MAX_ITERATIONS = 1000;

    // write the header information to the ppm file
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    // generate the Mandelbrot set and write it to the ppm file
    generateMandelbrotSet(fp, X_MIN, X_MAX, Y_MIN, Y_MAX, MAX_ITERATIONS, WIDTH, HEIGHT);

    // close the file
    fclose(fp);

    return 0;
}