//FormAI DATASET v1.0 Category: Fractal Generation ; Style: inquisitive
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Constants for fractal generation */
const float MIN_X = -2.0;
const float MAX_X = 2.0;
const float MIN_Y = -2.0;
const float MAX_Y = 2.0;
const int WIDTH = 1280;
const int HEIGHT = 720;
const int MAX_ITERATIONS = 255;

/* Function to calculate Mandelbrot fractal */
int mandelbrot(float x0, float y0) {
    float x = 0, y = 0;
    int i;
    for (i = 0; i < MAX_ITERATIONS; i++) {
        float xtemp = x * x - y * y + x0;
        y = 2 * x * y + y0;
        x = xtemp;
        if (x * x + y * y > 4.0) {
            return i;
        }
    }
    return MAX_ITERATIONS;
}

/* Main function to generate fractal and write to image file */
int main() {
    FILE *fp;
    fp = fopen("fractal.ppm", "w+");
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            float x0 = (x * (MAX_X - MIN_X) / WIDTH) + MIN_X;
            float y0 = (y * (MAX_Y - MIN_Y) / HEIGHT) + MIN_Y;
            int m = mandelbrot(x0, y0);
            int r = (int)(m*sin(x)*cos(y));
            int g = (int)(m*cos(x)*sin(y));
            int b = (int)(m*tan(x)*tan(y));
            fprintf(fp, "%d %d %d ", r, g, b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Fractal generation complete!\n");

    return 0;
}