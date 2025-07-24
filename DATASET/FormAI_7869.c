//FormAI DATASET v1.0 Category: Fractal Generation ; Style: calm
// This C program generates a Mandelbrot fractal

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ITER 200

int main(void) {
    complex double min = -2.3 - 1.3*I;
    complex double max = 1.3 + 1.3*I;
    int x, y, iter;
    double real, imag;
    complex double z, c;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            real = (double)x / (double)WIDTH * creal(max - min) + creal(min);
            imag = (double)y / (double)HEIGHT * cimag(max - min) + cimag(min);
            c = real + imag*I;
            z = 0;
            for (iter = 0; iter < MAX_ITER && cabs(z) < 2; iter++) {
                z = z*z + c;
            }
            putchar(iter == MAX_ITER ? ' ' : '@');
        }
        putchar('\n');
    }
    return 0;
}