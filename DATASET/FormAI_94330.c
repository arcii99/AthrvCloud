//FormAI DATASET v1.0 Category: Fractal Generation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

int main() {
    // Allocate space for the image
    unsigned char *image = (unsigned char*) malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(unsigned char));

    // Define the complex number plane
    double real_min = -2, real_max = 2, imaginary_min = -2, imaginary_max = 2;
    double real_range = real_max - real_min, imaginary_range = imaginary_max - imaginary_min;

    // Define the number of iterations
    int max_iterations = 1000;

    // Loop through every pixel in the image
    for (int x = 0; x < IMAGE_WIDTH; x++) {
        for (int y = 0; y < IMAGE_HEIGHT; y++) {
            // Map the pixel coordinates to the complex plane
            double real_part = (x / (double) IMAGE_WIDTH) * real_range + real_min;
            double imaginary_part = (y / (double) IMAGE_HEIGHT) * imaginary_range + imaginary_min;

            // Define the complex number
            double complex_real = real_part, complex_imaginary = imaginary_part;

            // Iterate the complex number until it escapes or the maximum number of iterations is reached
            int iterations = 0;
            while (iterations < max_iterations) {
                double next_complex_real = pow(complex_real, 2) - pow(complex_imaginary, 2) + real_part;
                double next_complex_imaginary = 2 * complex_real * complex_imaginary + imaginary_part;

                complex_real = next_complex_real;
                complex_imaginary = next_complex_imaginary;

                double magnitude_squared = pow(complex_real, 2) + pow(complex_imaginary, 2);
                if (magnitude_squared > 4) {
                    // The complex number has escaped, set the pixel value based on the number of iterations
                    double normalized_iterations = iterations / (double) max_iterations;
                    image[x + y * IMAGE_WIDTH] = (unsigned char) (255 * normalized_iterations);
                    break;
                }

                iterations++;
            }
        }
    }

    // Save the image to a PGM file
    FILE *output_file = fopen("fractal.pgm", "wb");
    fprintf(output_file, "P5\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
    fwrite(image, sizeof(unsigned char), IMAGE_WIDTH * IMAGE_HEIGHT, output_file);
    fclose(output_file);

    // Free the allocated memory
    free(image);

    // Print a success message
    printf("Fractal generation success!\n");

    return 0;
}