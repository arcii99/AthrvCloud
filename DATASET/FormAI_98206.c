//FormAI DATASET v1.0 Category: Fractal Generation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000
#define BAILOUT_RADIUS 2.0

void generate_fractal(FILE *file);

int main(int argc, char *argv[]) {
    FILE *output_file;

    if(argc < 2) {
         fprintf(stderr, "Usage: %s output_filename\n", argv[0]);
         exit(1);
    }

    output_file = fopen(argv[1], "w");

    generate_fractal(output_file);

    fclose(output_file);
    return 0;
}

void generate_fractal(FILE *file) {
    double xmin = -2.0;
    double xmax = 1.0;
    double ymin = -1.5;
    double ymax = 1.5;

    double x_step = (xmax - xmin) / (double) WIDTH;
    double y_step = (ymax - ymin) / (double) HEIGHT;

    double x, y, cx, cy, zx, zy, zx_new, zy_new, magnitude_squared;
    int i, j, n;
    unsigned char color;

    fprintf(file, "P5\n%d %d\n255\n", WIDTH, HEIGHT);

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            cx = xmin + (double) j * x_step;
            cy = ymax - (double) i * y_step;

            zx = cx;
            zy = cy;

            n = 0;
            while(n < MAX_ITER) {
                magnitude_squared = zx * zx + zy * zy;
                if(magnitude_squared > BAILOUT_RADIUS * BAILOUT_RADIUS) {
                    break;
                }
                zx_new = zx * zx - zy * zy + cx;
                zy_new = 2.0 * zx * zy + cy;
                zx = zx_new;
                zy = zy_new;
                n++;
            }

            color = n == MAX_ITER ? 0 : 255 - (unsigned char) (log((double) n) / log((double) MAX_ITER) * 255.0);
            fwrite(&color, sizeof(char), 1, file);
        }
    }
}