//FormAI DATASET v1.0 Category: Fractal Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 1000
#define HEIGHT 1000

// Define the complex plane dimensions
const double complex Min = -2.5 - 1.5 * I;
const double complex Max =  1.5 + 1.5 * I;

// Define the maximum number of iterations
const int MAX_ITERATIONS = 1000;

// Define the escape radius
const double ESCAPE_RADIUS = 2.0;

// Define the color pallette
const char COLORS[] = " .,-~:;=!*#$@";

int main()
{
    // Allocate space for the fractal image
    char fractal[WIDTH][HEIGHT];

    // Initialize the fractal image with blank spaces
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            fractal[i][j] = ' ';
        }
    }

    // Calculate the complex step size
    double complex Step = (Max - Min) / (WIDTH - 1);

    // Iterate over each point in the complex plane
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            double complex C = Min + i * Step + j * Step * I;
            double complex Z = C;
            int iterations = 0;

            // Perform the Mandelbrot iteration
            while (iterations < MAX_ITERATIONS && cabs(Z) < ESCAPE_RADIUS) {
                Z = Z * Z + C;
                iterations++;
            }

            // Set the color of the pixel based on the number of iterations
            int color_index = (int)(strlen(COLORS) * (double)iterations / MAX_ITERATIONS);
            fractal[i][j] = COLORS[color_index];
        }
    }

    // Output the fractal image
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            putchar(fractal[i][j]);
        }
        putchar('\n');
    }

    return 0;
}