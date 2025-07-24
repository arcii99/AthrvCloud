//FormAI DATASET v1.0 Category: Fractal Generation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

const int MAX_ITERATIONS = 1000;     // Maximum number of iterations
const double COLOR_QUOTIENT = 255.0; // To determine color value

// Function to check if a complex number is in the Mandelbrot set
int inMandelbrotSet(double real, double imaginary) {
    double zr = 0.0, zi = 0.0;  // Initialize zr and zi to 0
    int iterations = 0;         // Initialize iterations to 0

    // Iterate while absolute value of z is less than 2 and
    // number of iterations is less than the maximum allowed
    while (zr*zr + zi*zi < 4.0 && iterations < MAX_ITERATIONS) {
        double zr_temp = zr*zr - zi*zi + real; // Calculate values of new zr and zi
        zi = 2*zr*zi + imaginary;
        zr = zr_temp;
        iterations++; // Increment number of iterations
    }

    // Return 1 if the number is in the set, 0 otherwise
    return iterations == MAX_ITERATIONS ? 1 : 0;
}

// Function to generate the Mandelbrot fractal
void generateMandelbrotFractal(int width, int height, double startX, double endX,
                               double startY, double endY, char *filename) {
    FILE *fptr = fopen(filename, "w"); // Open file for writing

    // Write header for PPM file
    fprintf(fptr, "P3\n");
    fprintf(fptr, "%d %d\n", width, height);
    fprintf(fptr, "255\n");

    // Loop through each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double real = startX + (endX - startX) * x / (double) width;
            double imaginary = startY + (endY - startY) * y / (double) height;

            // Calculate the color value for the pixel based on its position
            int iter = inMandelbrotSet(real, imaginary);
            int red = (int) (iter * COLOR_QUOTIENT);
            int green = (int) (iter * COLOR_QUOTIENT);
            int blue = (int) (iter * COLOR_QUOTIENT);

            // Write color values to the file
            fprintf(fptr, "%d %d %d\n", red, green, blue);
        }
    }

    fclose(fptr); // Close the file
}

// Main function
int main() {
    generateMandelbrotFractal(800, 600, -2.0, 2.0, -2.0, 2.0, "fractal.ppm");
    return 0;
}