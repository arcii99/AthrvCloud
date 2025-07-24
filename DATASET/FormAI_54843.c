//FormAI DATASET v1.0 Category: Fractal Generation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000

int main(void) {
    int image[WIDTH][HEIGHT]; // The image will be stored as an array of integers representing pixel values
    int max_iterations = 100; // Maximum number of iterations
    double zoom = 1; // Initial zoom level
    double offsetX = -0.5; // Center of the fractal
    double offsetY = 0;
    double magnification = 1.0 / WIDTH * zoom; // Magnification factor

    // Loop over all the pixels in the image
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double cx = (x - WIDTH / 2.0) * magnification + offsetX; // Convert pixel coordinates to complex plane coordinates
            double cy = (y - HEIGHT / 2.0) * magnification + offsetY;
            double zx = 0;
            double zy = 0;
            int i;
            for (i = 0; i < max_iterations; i++) {
                double zx_new = zx * zx - zy * zy + cx; // Calculate the new value of z
                double zy_new = 2 * zx * zy + cy;
                if (zx_new * zx_new + zy_new * zy_new > 4) {
                    break; // The point is not in the Mandelbrot set
                }
                zx = zx_new;
                zy = zy_new;
            }
            // Set the pixel value based on the number of iterations it took to escape
            if (i == max_iterations) {
                image[x][y] = 0; // The point is likely in the Mandelbrot set
            } else {
                image[x][y] = 255 * i / max_iterations;
            }
        }
    }

    // Write the image to a file in PPM format
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            fputc(image[x][y], fp);
            fputc(image[x][y], fp);
            fputc(image[x][y], fp);
        }
    }
    fclose(fp);

    return 0;
}