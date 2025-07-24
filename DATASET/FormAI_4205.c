//FormAI DATASET v1.0 Category: Fractal Generation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WIDTH 80
#define HEIGHT 25

/* Function prototypes */
int mandelbrot(double, double, int);

int main(void)
{
    /* Variables to store the image data */
    char image[HEIGHT][WIDTH+1];
    int x, y;

    /* Set up the complex plane bounds */
    double xmin = -2.0, xmax = 2.0, ymin = -1.5, ymax = 1.5;

    /* Loop over each pixel and compute the corresponding complex number */
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            double real = xmin + (double)x / WIDTH * (xmax - xmin);
            double imag = ymin + (double)y / HEIGHT * (ymax - ymin);
            int value = mandelbrot(real, imag, 1000);
            char c;
            if (value == 0)
                c = '.';
            else if (value < 10)
                c = '+';
            else if (value < 20)
                c = '*';
            else if (value < 50)
                c = 'x';
            else if (value < 100)
                c = '$';
            else
                c = '#';
            image[y][x] = c;
        }
        image[y][WIDTH] = '\0';
    }

    /* Print the image */
    for (y = 0; y < HEIGHT; y++)
        printf("%s\n", image[y]);

    /* Success */
    return EXIT_SUCCESS;
}

/* Compute the Mandelbrot value for a given complex number */
int mandelbrot(double creal, double cimag, int max_iterations)
{
    double real = 0.0, imag = 0.0;
    int i;
    for (i = 0; i < max_iterations; i++) {
        double r2 = real * real;
        double i2 = imag * imag;
        if (r2 + i2 > 4.0)
            return i;
        double new_real = r2 - i2 + creal;
        double new_imag = 2.0 * real * imag + cimag;
        real = new_real;
        imag = new_imag;
    }
    return 0;
}