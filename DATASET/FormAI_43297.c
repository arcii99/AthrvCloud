//FormAI DATASET v1.0 Category: Fractal Generation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, j;
    int max_iterations = 255;
    double x, y, zx, zy, tmp;
    double cx = -0.7, cy = 0.27015;
    double radius = 2.0;
    double scale = 0.01;
    double x_min = -2.0, y_min = -1.5;
    int width = 80, height = 24;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            zx = x = ((double)j * scale) + x_min;
            zy = y = ((double)i * scale) + y_min;
            int iterations = 0;

            while (zx * zx + zy * zy < radius * radius &&
            iterations < max_iterations) {
                tmp = zx * zx - zy * zy + cx;
                zy = 2.0 * zx * zy + cy;
                zx = tmp;
                iterations++;
            }

            if (iterations == max_iterations) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}