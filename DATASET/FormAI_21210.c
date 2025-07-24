//FormAI DATASET v1.0 Category: Fractal Generation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

/* Function to generate fractals */
void generateFractal(int iterations, int width)
{
    int i, j, k;
    double x, y;
    double x1 = -1.5, x2 = 1.5, y1 = -1.5, y2 = 1.5;
    double zoom = 1.0 / (double)width;
    double centerX = (x1 + x2) / 2.0;
    double centerY = (y1 + y2) / 2.0;

    /* Create a 2D array to hold the result */
    int mandelbrot[width][width];

    /* Generate the fractal */
    for (i = 0; i < width; i++) {
        for (j = 0; j < width; j++) {
            x = (double)i * zoom - centerX;
            y = (double)j * zoom - centerY;

            /* Apply the Mandelbrot formula */
            double x0 = x;
            double y0 = y;
            k = 0;
            while (k < iterations && (x*x + y*y) < 4.0) {
                double temp = x*x - y*y + x0;
                y = 2.0*x*y + y0;
                x = temp;
                k++;
            }

            mandelbrot[i][j] = k;
        }
    }

    /* Print the result */
    for (i = 0; i < width; i++) {
        for (j = 0; j < width; j++) {
            if (mandelbrot[i][j] == iterations) {
                printf("*");
            } else if (mandelbrot[i][j] > iterations / 2) {
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* Driver function */
int main()
{
    int iterations = 50;
    int width = 100;
    generateFractal(iterations, width);
    return 0;
}