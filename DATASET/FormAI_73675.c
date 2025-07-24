//FormAI DATASET v1.0 Category: Fractal Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000
#define BAILOUT 2

void draw_fractal(double complex c, unsigned char *pixel_buffer) {
    // Initialize pixel coordinates
    int pix_x, pix_y;

    // Set up variables for iterating over real and imaginary axes
    double real_start = -2.0, real_end = 1.0, real_range = real_end - real_start;
    double imag_start = -1.5, imag_end = 1.5, imag_range = imag_end - imag_start;

    // Iterate over each pixel and calculate escape time
    for (pix_y = 0; pix_y < HEIGHT; pix_y++) {
        for (pix_x = 0; pix_x < WIDTH; pix_x++) {
            double complex z = ((double) pix_x / WIDTH) * real_range + real_start
                        + ((double) pix_y / HEIGHT) * imag_range * I + c;
            double complex z0 = z;
            int iter = 0;
            while (cabs(z) < BAILOUT && iter < MAX_ITER) {
                z = cpow(z, 2) + z0;
                iter++;
            }
            // Calculate color to assign to pixel based on escape time
            if (iter == MAX_ITER) {
                pixel_buffer[(pix_x + pix_y * WIDTH) * 3] = 0;
                pixel_buffer[(pix_x + pix_y * WIDTH) * 3 + 1] = 0;
                pixel_buffer[(pix_x + pix_y * WIDTH) * 3 + 2] = 0; // Black
            } else {
                double t = (double) iter / MAX_ITER;
                pixel_buffer[(pix_x + pix_y * WIDTH) * 3] = (unsigned char) (9 * (1 - t) * t * t * t * 255);
                pixel_buffer[(pix_x + pix_y * WIDTH) * 3 + 1] = (unsigned char) (15 * (1 - t) * (1 - t) * t * t * 255);
                pixel_buffer[(pix_x + pix_y * WIDTH) * 3 + 2] = (unsigned char) (8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); // Color gradient
            }
        }
    }
}

int main(void) {
    // Allocate memory for pixel buffer
    unsigned char *pixel_buffer = malloc(WIDTH * HEIGHT * 3);
    if (!pixel_buffer) {
        fprintf(stderr, "Failed to allocate memory for pixel buffer.\n");
        exit(1);
    }
    // Calculate and draw fractal with initial complex value
    double complex c = -0.75 + 0.1 * I;
    draw_fractal(c, pixel_buffer);

    // Create image file
    FILE *fp;
    fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
    fprintf(fp, "255\n");

    fwrite(pixel_buffer, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);
    free(pixel_buffer);
    printf("Fractal image generated successfully.\n");
    return 0;
}