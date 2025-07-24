//FormAI DATASET v1.0 Category: Fractal Generation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 600
#define HEIGHT 600
#define MAX_ITER 1000

int palette[][3] = {
    {0, 0, 0},      // black
    {255, 0, 0},    // red
    {0, 255, 0},    // green
    {0, 0, 255},    // blue
    {255, 255, 0},  // yellow
    {255, 0, 255},  // magenta
    {0, 255, 255},  // cyan
    {255, 255, 255} // white
};

int num_colors = sizeof(palette) / sizeof(palette[0]);

int mandelbrot(double cx, double cy) {
    double x = 0.0, y = 0.0;
    int i;
    for (i = 0; i < MAX_ITER; i++) {
        double x2 = x*x, y2 = y*y;
        if (x2 + y2 > 4.0) return i;
        double xy = x*y;
        x = x2 - y2 + cx;
        y = 2.0 * xy + cy;
    }
    return MAX_ITER-1;
}

void draw_fractal(int image[][HEIGHT], double x_min, double x_max, double y_min,
                  double y_max) {
    int i, j, k;
    double x, y;
    double x_step = (x_max - x_min) / WIDTH;
    double y_step = (y_max - y_min) / HEIGHT;
    for (i = 0, x = x_min; i < WIDTH; i++, x += x_step) {
        for (j = 0, y = y_min; j < HEIGHT; j++, y += y_step) {
            int color = mandelbrot(x, y);
            for (k = 0; k < 3; k++) {
                image[i][j] = palette[color % num_colors][k];
            }
        }
    }
}

int main() {
    int image[WIDTH][HEIGHT];
    double x_min = -2.0, x_max = 1.0, y_min = -1.5, y_max = 1.5;
    draw_fractal(image, x_min, x_max, y_min, y_max);
    FILE *fp = fopen("fractal.ppm", "w");
    fprintf(fp, "P3\n%d %d\n%d\n", WIDTH, HEIGHT, 255);
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            fprintf(fp, "%d %d %d ", image[i][j], image[i][j], image[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}