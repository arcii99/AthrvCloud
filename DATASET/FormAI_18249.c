//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Claude Shannon
#include <stdio.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 2000

// Define the initial complex number
#define INITIAL_REAL -1
#define INITIAL_IMAGINARY 0

// Define the step size for the real and imaginary components
#define STEP_SIZE 0.005

// Define the height and width of the image in pixels
#define HEIGHT 600
#define WIDTH 600

// Define the color of the fractal
#define COLOR "black"

int main() {
    // Define the real and imaginary parts of the current complex number
    double current_real = INITIAL_REAL;
    double current_imaginary = INITIAL_IMAGINARY;

    // Iterate over each pixel in the image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Define the current complex number to be calculated
            double z_real = current_real;
            double z_imaginary = current_imaginary;

            // Iterate the complex number until it either diverges or reaches the maximum number of iterations
            int i;
            for (i = 0; i < MAX_ITERATIONS; i++) {
                // Calculate the next value of the complex number
                double z_real_temp = z_real * z_real - z_imaginary * z_imaginary + current_real;
                double z_imaginary_temp = 2 * z_real * z_imaginary + current_imaginary;

                z_real = z_real_temp;
                z_imaginary = z_imaginary_temp;

                // Check if the complex number has diverged
                if (z_real * z_real + z_imaginary * z_imaginary > 4) {
                    break;
                }
            }

            // Determine the color of the pixel based on the number of iterations before divergence
            if (i == MAX_ITERATIONS) {
                printf("<rect x=\"%d\" y=\"%d\" width=\"1\" height=\"1\" fill=\"%s\" />\n", x, y, COLOR);
            } else {
                // Map the number of iterations to a color value
                int color_index = i % 16;
                char* colors[] = {"#000000", "#001100", "#002200", "#003300", "#004400", "#005500", "#006600", "#007700", "#008800", "#009900", "#00AA00", "#00BB00", "#00CC00", "#00DD00", "#00EE00", "#00FF00"};
                printf("<rect x=\"%d\" y=\"%d\" width=\"1\" height=\"1\" fill=\"%s\" />\n", x, y, colors[color_index]);
            }

            // Update the real component for the next pixel
            current_real += STEP_SIZE;
        }

        // Update the imaginary component for the next row of pixels
        current_imaginary += STEP_SIZE;

        // Reset the real component to its initial value for the next row of pixels
        current_real = INITIAL_REAL;
    }

    return 0;
}