//FormAI DATASET v1.0 Category: Fractal Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int maxiterations = 100;
    int width = 500;
    int height = 500;
    int x, y, i, j;
    double zx, zy, cx, cy;
    double min_x = -1.5;
    double max_x = 1.5;
    double min_y = -1.5;
    double max_y = 1.5;
    double zoom = 1.0;
    double dx = (max_x - min_x) / width;
    double dy = (max_y - min_y) / height;
    double c_real[10];
    double c_imag[10];
    int c_count = 0;

    for (i = 0; i < 10; ++i) {
        c_real[i] = ((double) rand() / (double) RAND_MAX) * 2 - 1;
        c_imag[i] = ((double) rand() / (double) RAND_MAX) * 2 - 1;
    }

    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            zx = 0.0;
            zy = 0.0;

            cx = (x * dx - dx / 2.0) / zoom + min_x;
            cy = (y * dy - dy / 2.0) / zoom + min_y;

            for (i = 0; i < maxiterations; ++i) {
                double new_zx, new_zy;
                double v;
                double r, theta;

                if (c_count == 0) {
                    new_zx = zx * zx - zy * zy + cx;
                    new_zy = 2 * zx * zy + cy;

                    zx = new_zx;
                    zy = new_zy;
                } else {
                    v = 0;

                    for (j = 0; j < c_count; ++j) {
                        r = sqrt(zx * zx + zy * zy);
                        theta = atan2(zy, zx);

                        new_zx = pow(r, 2.0 / v) * cos(v * theta) + c_real[j];
                        new_zy = pow(r, 2.0 / v) * sin(v * theta) + c_imag[j];

                        zx = new_zx;
                        zy = new_zy;

                        v += 1.0;
                    }
                }

                if (zx*zx + zy*zy > 4.0) break;
            }

            if (i == maxiterations) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}