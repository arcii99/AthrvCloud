//FormAI DATASET v1.0 Category: Fractal Generation ; Style: relaxed
#include <stdio.h>

int main() {
    // Setting up variables
    int iterations = 1000;
    int width = 80;
    int height = 40;
    double zoom = 1.5;
    double x_offset = 0;
    double y_offset = 0;

    // Loop for each pixel in the screen
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the real and imaginary parts of the complex number
            double real = (double)x / width * zoom - zoom / 2 + x_offset;
            double imag = (double)y / height * zoom - zoom / 2 + y_offset;

            // Set up the initial values for the fractal
            double z_real = real;
            double z_imag = imag;
            int i = 0;

            // Loop until the maximum number of iterations is reached or we escape
            while (i < iterations && z_real * z_real + z_imag * z_imag < 4.0) {
                // Calculate the next value of the fractal
                double new_z_real = z_real * z_real - z_imag * z_imag + real;
                double new_z_imag = 2 * z_real * z_imag + imag;

                // Update the values
                z_real = new_z_real;
                z_imag = new_z_imag;
                i++;
            }

            // Determine the color of the pixel based on how quickly we escaped
            char pixel = i == iterations ? ' ' : '.';
            printf("%c", pixel);
        }
        printf("\n");
    }

    return 0;
}