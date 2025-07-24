//FormAI DATASET v1.0 Category: Fractal Generation ; Style: calm
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ITERATIONS 100
#define MAX_COORDINATES 10000

// Define global variables
int iterations = 0;
float x_coordinates[MAX_COORDINATES];
float y_coordinates[MAX_COORDINATES];

// Fractal function
void generate_fractal(float x, float y) {

    // Define local variables
    float real = x;
    float imag = y;
    float z_real = 0;
    float z_imag = 0;

    // Iterate through calculations
    while (iterations < MAX_ITERATIONS) {

        // Implement z = z^2 + c formula
        z_real = (z_real * z_real) - (z_imag * z_imag) + real;
        z_imag = 2 * z_real * z_imag + imag;
        iterations++;

        // Check for divergence
        if ((z_real * z_real + z_imag * z_imag) > 4) {
            return;
        }
    }

    // Add coordinates to global arrays
    x_coordinates[iterations-1] = x;
    y_coordinates[iterations-1] = y;
}

int main() {

    // Define local variables
    int i, j;
    float x_min = -2.0;
    float x_max = 2.0;
    float y_min = -2.0;
    float y_max = 2.0;
    float x_step = 0.01;
    float y_step = 0.01;

    // Iterate through x and y values
    for (float x = x_min; x <= x_max; x += x_step) {
        for (float y = y_min; y <= y_max; y += y_step) {

            // Reset iteration counter
            iterations = 0;

            // Generate fractal coordinates
            generate_fractal(x, y);
        }
    }

    // Display fractal
    for (i = 0; i < MAX_ITERATIONS; i++) {
        for (j = 0; j < MAX_ITERATIONS; j++) {

            // Check for fractal coordinates
            int k;
            for (k = 0; k < MAX_COORDINATES; k++) {
                if (x_coordinates[k] == j && y_coordinates[k] == i) {
                    printf("*");
                    break;
                }
            }

            // Display blank space if no coordinates found
            if (k == MAX_COORDINATES) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}