//FormAI DATASET v1.0 Category: Fractal Generation ; Style: curious
#include <stdio.h>
#include <math.h>

int main() {
    int resolution = 512;
    double zoom = 1.0;
    double x_center = -0.5;
    double y_center = 0.0;

    int max_iter = 1024;
    int x, y, n;
    double cx, cy, zx, zy, temp;

    // Creating the image array
    int image[resolution][resolution];
    for (y = 0; y < resolution; y++) {
        for (x = 0; x < resolution; x++) {
            image[y][x] = 0;
        }
    }

    // Main loop through all the pixels
    for (y = 0; y < resolution; y++) {
        for (x = 0; x < resolution; x++) {
            cx = (x - resolution / 2.0) * (4.0/(double)resolution) / zoom + x_center;
            cy = (y - resolution / 2.0) * (4.0/(double)resolution) / zoom + y_center;
            zx = 0.0;
            zy = 0.0;
            n = 0;
            while (zx * zx + zy * zy < 4 && n < max_iter) {
                temp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = temp;
                n++;
            }
            image[y][x] = n % 256;
        }
    }

    // Printing the image array to a PGM file
    FILE *fp = fopen("fractal.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", resolution, resolution);
    for (y = 0; y < resolution; y++) {
        for (x = 0; x < resolution; x++) {
            fputc(image[y][x], fp);
        }
    }
    fclose(fp);

    return 0;
}