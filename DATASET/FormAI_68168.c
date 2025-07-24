//FormAI DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 600
#define HEIGHT 600
#define MAX_ITERATIONS 1000

typedef struct {
    double r;
    double i;
} Complex;

int main() {

    // Declare variables
    int i, j, n;
    double x, y;
    Complex c, z;

    // Initialize random seed
    srand(time(NULL));

    // Generate a random complex number
    c.r = ((double)rand() / (double)RAND_MAX) * 4 - 2;
    c.i = ((double)rand() / (double)RAND_MAX) * 4 - 2;

    // Initialize an empty image
    unsigned char image[WIDTH][HEIGHT];

    // Loop through all pixels in the image
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {

            // Convert pixel coordinates to Mandelbrot coordinates
            x = (double)i / WIDTH * 4 - 2;
            y = (double)j / HEIGHT * 4 - 2;

            // Initialize z to the current pixel's coordinates
            z.r = x;
            z.i = y;

            // Iterate until the maximum number of iterations is reached
            n = 0;
            while (n < MAX_ITERATIONS) {
                // Calculate z^2 + c
                Complex z_squared = {z.r * z.r - z.i * z.i, 2 * z.r * z.i};
                z.r = z_squared.r + c.r;
                z.i = z_squared.i + c.i;

                // If z has escaped the circle of radius 2, set the pixel color and exit the loop
                if (z.r * z.r + z.i * z.i > 4) {
                    image[i][j] = 255 - n * 255 / MAX_ITERATIONS;
                    break;
                }
                n++;
            }
            // If the loop completed without escaping, set the pixel color to black
            if (n == MAX_ITERATIONS) {
                image[i][j] = 0;
            }
        }
    }

    // Output the image as a PGM file
    FILE *file = fopen("fractal.pgm", "wb");
    fprintf(file, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, 1, WIDTH * HEIGHT, file);
    fclose(file);

    return 0;
}