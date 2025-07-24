//FormAI DATASET v1.0 Category: Fractal Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800

int color(int iter) // function to create fractal color
{
    int r, g, b;
    if (iter == -1) {
        r = 0;
        g = 0;
        b = 0;
    } else {
        r = (iter * 7) % 255;
        g = (iter * 15) % 255;
        b = (iter * 25) % 255;
    }
    return (r << 16) + (g << 8) + b;
}

int mandelbrot(double x, double y, int max_iter) // function to calculate Mandelbrot iteration
{
    int iter;
    double cx, cy, zx, zy, zx_new;
    cx = x;
    cy = y;
    zx = 0;
    zy = 0;
    iter = 0;

    for (int i = 0; i < max_iter; i++) {
        zx_new = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = zx_new;
        if (sqrt(zx * zx + zy * zy) > 2) {
            iter = i;
            break;
        }
    }
    return iter;
}

int main()
{
    int max_iter = 1000;
    double x_min = -2.0;
    double x_max = 2.0;
    double y_min = -2.0;
    double y_max = 2.0;
    double x, y;
    int c;

    FILE *fp = fopen("fractal.ppm", "wb");

    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
    fprintf(fp, "255\n");

    for(int i = 0; i < HEIGHT; i++) {
        y = y_min + (y_max - y_min) * ((double) i / HEIGHT);
        for(int j = 0; j < WIDTH; j++) {
            x = x_min + (x_max - x_min) * ((double) j / WIDTH);
            c = mandelbrot(x, y, max_iter);
            int color_val = color(c);
            fwrite(&color_val, 3, 1, fp);
        }
    }

    fclose(fp);
    printf("Fractal image generated successfully!\n");
    return 0;
}