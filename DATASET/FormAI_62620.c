//FormAI DATASET v1.0 Category: Fractal Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 5000
#define NUM_COLORS 5

typedef struct {
    double real;
    double imag;
} Complex;

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

Complex c = {-0.75, 0.15};
double zoom = 1.0;

Color colors[NUM_COLORS] = {
    {66, 30, 15},
    {25, 7, 26},
    {9, 1, 47},
    {4, 4, 73},
    {0, 7, 100}
};

int is_mandelbrot(Complex c) {
    Complex z = {0, 0};

    for (int i = 0; i < MAX_ITER; i++) {
        double re = z.real * z.real - z.imag * z.imag + c.real;
        double im = 2 * z.real * z.imag + c.imag;
        z.real = re;
        z.imag = im;

        if (z.real * z.real + z.imag * z.imag > 4) {
            return 0;
        }
    }
    
    return 1;
}

Color get_color(int iter) {
    if (iter == MAX_ITER) {
        return colors[NUM_COLORS - 1];
    }

    int index = iter % NUM_COLORS;
    return colors[index];
}

int main() {
    FILE *fp;
    char filename[] = "fractal.ppm";

    fp = fopen(filename, "wb");
    fprintf(fp, "P6 %d %d 255\n", WIDTH, HEIGHT);

    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            Complex z;
            z.real = ((double) x / WIDTH - 0.5) / zoom * 3.0 - c.real;
            z.imag = ((double) y / HEIGHT - 0.5) / zoom * 2.0 - c.imag;

            if (is_mandelbrot(z)) {
                Color color = get_color(MAX_ITER);
                fputc(color.r, fp);
                fputc(color.g, fp);
                fputc(color.b, fp);
            } else {
                int iter;
                for (iter = 0; iter < MAX_ITER; iter++) {
                    Complex z_next;
                    z_next.real = z.real * z.real - z.imag * z.imag + c.real;
                    z_next.imag = 2 * z.real * z.imag + c.imag;
                    z = z_next;

                    if (z.real * z.real + z.imag * z.imag > 4) {
                        Color color = get_color(iter);
                        fputc(color.r, fp);
                        fputc(color.g, fp);
                        fputc(color.b, fp);
                        break;
                    }
                }
            }
        }
    }

    fclose(fp);
    return 0;
}