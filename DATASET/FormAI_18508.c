//FormAI DATASET v1.0 Category: Fractal Generation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800 // Width of generated image
#define HEIGHT 600 // Height of generated image
#define MAX_ITERATIONS 50 // Maximum number of iterations
#define SCALE 1.0 // Zoom level

struct complex { // Struct to represent complex numbers
    double real;
    double imag;
};

int mandelbrot(struct complex c) { // Calculate Mandelbrot set
    int i;
    struct complex z, z_last;
    z.real = 0;
    z.imag = 0;
    for (i = 0; i < MAX_ITERATIONS; i++) {
        z_last = z;
        z.real = z_last.real * z_last.real - z_last.imag * z_last.imag + c.real;
        z.imag = 2 * z_last.real * z_last.imag + c.imag;
        if (sqrt(z.real * z.real + z.imag * z.imag) > 2) {
            return i; // Diverged
        }
    }
    return -1; // Converged
}

void generate_fractal(char *filename) {
    FILE *fp;
    int x, y, count;
    struct complex c;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }
    fprintf(fp, "P2\n%d %d\n255\n", WIDTH, HEIGHT);
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            c.real = ((double) x - WIDTH / 2) / (0.5 * SCALE * WIDTH);
            c.imag = ((double) y - HEIGHT / 2) / (0.5 * SCALE * HEIGHT);
            count = mandelbrot(c);
            if (count == -1) {
                fprintf(fp, "255 ");
            } else {
                fprintf(fp, "%d ", count * 5);
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    generate_fractal("fractal.pgm");
    return 0;
}