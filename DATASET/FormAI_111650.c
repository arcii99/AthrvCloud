//FormAI DATASET v1.0 Category: Fractal Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

/* Function to check if a point is in the Mandelbrot set */
int in_mandelbrot_set(double x, double y)
{
    int iterations = 0;
    double z_real = 0, z_imaginary = 0;
    double temp;

    while (iterations < MAX_ITERATIONS) {
        temp = z_real * z_real - z_imaginary * z_imaginary + x;
        z_imaginary = 2 * z_real * z_imaginary + y;
        z_real = temp;

        if (z_real * z_real + z_imaginary * z_imaginary > 4) {
            return 0;
        }

        iterations++;
    }

    return 1;
}

/* Function to generate the fractal and print it to the terminal */
void generate_fractal(int width, int height)
{
    double x_min = -2.5, x_max = 1;
    double y_min = -1, y_max = 1;
    double x, y;

    for (int j = 0; j < height; j++) {
        y = y_min + j * (y_max - y_min) / height;
        for (int i = 0; i < width; i++) {
            x = x_min + i * (x_max - x_min) / width;

            if (in_mandelbrot_set(x, y)) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int width = 80, height = 40;

    generate_fractal(width, height);

    return 0;
}