//FormAI DATASET v1.0 Category: Fractal Generation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define the width and height of the fractal image
#define WIDTH 640
#define HEIGHT 480

// Define the maximum number of iterations for the fractal calculation
#define MAX_ITERATIONS 1000

// Define the coordinates and zoom level of the fractal
double x_center = -0.5;
double y_center = 0.0;
double zoom = 1.0;

int main(void) {
    // Allocate memory for the fractal image
    unsigned char *image = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));

    // Check if the memory allocation was successful
    if (image == NULL) {
        printf("Error: Failed to allocate memory for the image!\n");
        return 1;
    }

    // Initialize the fractal image to all black pixels
    memset(image, 0, WIDTH * HEIGHT);

    // Loop through all the pixels in the fractal image
    for (unsigned int y = 0; y < HEIGHT; y++) {
        for (unsigned int x = 0; x < WIDTH; x++) {
            // Calculate the complex number corresponding to the pixel
            double c_real = (x - WIDTH / 2.0) * 4.0 / (zoom * WIDTH) + x_center;
            double c_imag = (y - HEIGHT / 2.0) * 4.0 / (zoom * HEIGHT) + y_center;

            // Initialize the complex number z to zero
            double z_real = 0.0;
            double z_imag = 0.0;

            // Loop through the iterations of the fractal calculation
            unsigned int i;
            for (i = 0; i < MAX_ITERATIONS; i++) {
                // Calculate the real and imaginary components of z^2 + c
                double z_real_squared = z_real * z_real;
                double z_imag_squared = z_imag * z_imag;
                double z_squared_real_imag = z_real * z_imag * 2.0;
                double real = z_real_squared - z_imag_squared + c_real;
                double imag = z_squared_real_imag + c_imag;

                // Check if the magnitude of z has exceeded the escape radius of 2
                if (z_real_squared + z_imag_squared > 4.0) {
                    break;
                }

                // Update the value of z
                z_real = real;
                z_imag = imag;
            }

            // Calculate the color of the pixel based on the number of iterations
            unsigned char color = 255 - (unsigned char)(255.0 * i / MAX_ITERATIONS);

            // Set the color of the pixel in the fractal image
            image[y * WIDTH + x] = color;
        }
    }

    // Print a message indicating that the fractal has been generated
    printf("Fractal generated successfully!\n");

    // Free the memory allocated for the fractal image
    free(image);

    // Return 0 to indicate success
    return 0;
}