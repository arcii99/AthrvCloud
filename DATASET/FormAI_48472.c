//FormAI DATASET v1.0 Category: Fractal Generation ; Style: interoperable
#include <stdio.h>
#include <complex.h>

int main() {

    // Setting up the constants for the Mandelbrot Set
    const int WIDTH = 80;
    const int HEIGHT = 40;
    const double X_MIN = -2;
    const double X_MAX = 1;
    const double Y_MIN = -1;
    const double Y_MAX = 1;

    // Setting up the complex numbers
    double complex z, c;

    // Setting up the variables for the loop
    int i, j, k;
    int MAX_ITER = 1000;
    double STEP_X = (X_MAX - X_MIN) / WIDTH;
    double STEP_Y = (Y_MAX - Y_MIN) / HEIGHT;

    // Iterating through the pixels of the image
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {

            // Calculating the complex number based on the pixel coordinates
            double x = X_MIN + i * STEP_X;
            double y = Y_MIN + j * STEP_Y;
            c = x + y * I;

            // Setting z = 0
            z = 0;

            // Iterating through the equation until it diverges or reaches the maximum number of iterations
            for (k = 0; k < MAX_ITER; k++) {
                z = z * z + c;
                if (cabs(z) > 2.0) {
                    break;
                }
            }

            // Setting the color based on the number of iterations
            int color = k % 16;

            // Displaying the pixel with the appropriate color
            printf("\033[48;5;%dm ", 16 + color);

        }

        // Moving to the next line after each row is completed
        printf("\033[0m\n");
    }

    // Exiting the program
    return 0;
}