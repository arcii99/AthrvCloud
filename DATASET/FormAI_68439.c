//FormAI DATASET v1.0 Category: Fractal Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define IMG_WIDTH 500
#define IMG_HEIGHT 500
#define X_MIN -2.5
#define X_MAX 1
#define Y_MIN -1
#define Y_MAX 1

double mandelbrot(double real, double imag) {
    double zReal = real, zImag = imag;
    int i;
    for (i = 0; i < MAX_ITERATIONS; i++) {
        double nextZReal = zReal * zReal - zImag * zImag + real;
        double nextZImag = 2 * zReal * zImag + imag;
        if (nextZReal * nextZReal + nextZImag * nextZImag > 4)
            return ((double)i) / MAX_ITERATIONS;
        zReal = nextZReal;
        zImag = nextZImag;
    }
    return 0.0;
}

int main() {
    double xStep = (X_MAX - X_MIN) / IMG_WIDTH;
    double yStep = (Y_MAX - Y_MIN) / IMG_HEIGHT;

    FILE *fp = fopen("mandelbrot.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", IMG_WIDTH, IMG_HEIGHT);

    int x, y;
    for (y = 0; y < IMG_HEIGHT; y++) {
        double imag = Y_MIN + y * yStep;
        for (x = 0; x < IMG_WIDTH; x++) {
            double real = X_MIN + x * xStep;
            double mandelbrotValue = mandelbrot(real, imag);
            char r = (int)(mandelbrotValue * 255) % 256;
            char g = (int)(mandelbrotValue * 255) % 256;
            char b = (int)(mandelbrotValue * 255) % 256;
            fwrite(&r, 1, 1, fp);
            fwrite(&g, 1, 1, fp);
            fwrite(&b, 1, 1, fp);
        }
    }
    fclose(fp);

    return 0;
}