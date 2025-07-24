//FormAI DATASET v1.0 Category: Fractal Generation ; Style: lively
// Welcome to the world of Fractals in C Programming!
// Today, we're going to generate the Mandelbrot Set using escape time algorithm
// Get ready for a journey into the world of infinite beauty and complexity!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 80 // Width of the output image in characters
#define HEIGHT 40 // Height of the output image in characters
#define MAX_ITERATIONS 10000 // Maximum number of iterations for the escape time algorithm

int main()
{

    // Define the (x,y)-coordinates of the region of the complex plane we want to explore
    const double x_min = -2.0;
    const double x_max = 1.0;
    const double y_min = -1.5;
    const double y_max = 1.5;

    // Define the size of the steps we will take between pixels
    const double x_step = (x_max - x_min) / WIDTH;
    const double y_step = (y_max - y_min) / HEIGHT;

    // Define a buffer to store our final image
    char buffer[HEIGHT][WIDTH + 1]; // We add 1 to the width to store the newline character

    // Loop over every pixel in our region of interest
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {

            // Compute the complex number corresponding to this pixel
            double complex c = x_min + i * x_step + (y_min + j * y_step) * I;

            // Initialize the complex number z to zero
            double complex z = 0;

            // Initialize the iteration counter to zero
            int iteration = 0;

            // Perform the escape time algorithm
            while (cabs(z) < 2 && iteration < MAX_ITERATIONS) {
                z = z * z + c;
                iteration++;
            }

            // If the algorithm converged within the maximum number of iterations,
            // color this pixel black. Otherwise, color it white.
            if (iteration == MAX_ITERATIONS) {
                buffer[j][i] = ' ';
            } else {
                buffer[j][i] = '#';
            }
        }
        // After each row, add a newline character to the buffer
        buffer[j][WIDTH] = '\n';
    }

    // Print out the image to the console
    for (int j = 0; j < HEIGHT; j++) {
        printf("%s", buffer[j]);
    }

    // Exit the program successfully
    return 0;
}