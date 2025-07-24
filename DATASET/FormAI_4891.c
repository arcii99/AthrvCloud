//FormAI DATASET v1.0 Category: Fractal Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define WIDTH 100
#define HEIGHT 40
#define MAX_ITERATIONS 10000
#define ESCAPE_RADIUS 1000000.0

// Function to calculate the mandelbrot set
void mandelbrot(int iterations[WIDTH][HEIGHT]) {
    double x, y, x0, y0, xtemp, ytemp, modulus_squared;
    int i, j, n;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            x0 = ((double)i - WIDTH/2) / (WIDTH/4.0);
            y0 = ((double)j - HEIGHT/2) / (HEIGHT/4.0);

            x = 0.0;
            y = 0.0;
            n = 0;

            while (n < MAX_ITERATIONS) {
                xtemp = x * x - y * y + x0;
                ytemp = 2 * x * y + y0;

                modulus_squared = xtemp * xtemp + ytemp * ytemp;

                if (modulus_squared > ESCAPE_RADIUS) {
                    break;
                }

                x = xtemp;
                y = ytemp;

                n++;
            }

            iterations[i][j] = n;
        }
    }
}

// Function to print the fractal to the console
void print_fractal(int iterations[WIDTH][HEIGHT]) {
    int i, j;

    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            if (iterations[i][j] == MAX_ITERATIONS) {
                printf(" ");
            } else if (iterations[i][j] > MAX_ITERATIONS / 2) {
                printf(".");
            } else if (iterations[i][j] > MAX_ITERATIONS / 4) {
                printf(":");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int iterations[WIDTH][HEIGHT];

    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate the mandelbrot set
    mandelbrot(iterations);

    // Print the fractal to the console
    print_fractal(iterations);

    return 0;
}