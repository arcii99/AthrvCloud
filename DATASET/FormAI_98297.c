//FormAI DATASET v1.0 Category: Fractal Generation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <complex.h>

#define SIZE 512

// Function to generate a fractal pattern
void generateFractal(int iterations, double zoom, double complex center) {
    int i, j, k;
    double complex z, c, temp;
    bool inSet;
    double realMin = center - zoom/2;
    double imagMax = center + zoom/2;
    double stepSize = zoom/SIZE;
    double imag, real;

    // Iterate over each pixel in the image
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            inSet = true;
            real = realMin + j*stepSize;
            imag = imagMax - i*stepSize;
            c = real + imag*I;
            z = c;

            // Check if the current point is in the Mandelbrot set
            for(k = 0; k < iterations; k++) {
                temp = z*z + c;
                if(cabs(temp) > 2) {
                    inSet = false;
                    break;
                }
                z = temp;
            }

            // Print the pixel color to the console
            if(inSet) {
                printf("%s", "\033[0;37m#\033[0m");
            } else {
                printf("%s", "\033[0;31m#033[0m");
            }
        }
        printf("\n");
    }
}

int main() {
    // Set the initial parameters for the fractal
    int iterations = 50;
    double zoom = 2;
    double complex center = -0.5 + 0*I;

    // Generate and display the fractal pattern
    generateFractal(iterations, zoom, center);

    return 0;
}