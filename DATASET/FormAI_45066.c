//FormAI DATASET v1.0 Category: Fractal Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 600

int main(void) {
    FILE *fp;
    int i, j, n, x, y;
    double cx, cy, zx, zy, temp;
    double x_min = -2.0, x_max = 2.0, y_min = -2.0, y_max = 2.0;
    double zoom_factor = 1.0;
    unsigned char image[WIDTH][HEIGHT][3];

    fp = fopen("fractal.ppm", "wb");  // Output image file

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Set the image's RGB values to black
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            image[i][j][0] = 0;
            image[i][j][1] = 0;
            image[i][j][2] = 0;
        }
    }

    // Generate the fractal
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            cx = x_min + (x * (x_max - x_min) / (double) WIDTH) / zoom_factor;
            cy = y_min + (y * (y_max - y_min) / (double) HEIGHT) / zoom_factor;
            zx = 0.0;
            zy = 0.0;
            n = 0;

            while (zx * zx + zy * zy <= 4.0 && n < 255) {
                temp = zx * zx - zy * zy + cx;
                zy = 2.0 * zx * zy + cy;
                zx = temp;
                n++;
            }

            // Set the pixel color based on the number of iterations
            if (n == 255) {
                image[x][y][0] = 0;
                image[x][y][1] = 0;
                image[x][y][2] = 0;
            } else {
                image[x][y][0] = n * 3 % 255;  // Red
                image[x][y][1] = n * 7 % 255;  // Green
                image[x][y][2] = n * 11 % 255;  // Blue
            }
        }
    }

    // Output the image to the file in PPM format
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
    fprintf(fp, "255\n");

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            fwrite(image[i][j], sizeof(unsigned char), 3, fp);
        }
    }

    fclose(fp);

    return 0;
}