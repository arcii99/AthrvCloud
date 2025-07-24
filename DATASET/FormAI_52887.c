//FormAI DATASET v1.0 Category: Fractal Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define RADIUS 2.0

struct ComplexNumber {
    double real;
    double imaginary;
};

int computeMandelbrot(struct ComplexNumber c) {
    int i = 0;
    struct ComplexNumber z = {0, 0};
    while (i < MAX_ITERATIONS && sqrt(z.real*z.real + z.imaginary*z.imaginary) < RADIUS) {
        double zReal = z.real*z.real - z.imaginary*z.imaginary + c.real;
        double zImaginary = 2*z.real*z.imaginary + c.imaginary;
        z = (struct ComplexNumber) {zReal, zImaginary};
        i++;
    }
    return i;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image width>\n", argv[0]);
        exit(1);
    }
    int width = atoi(argv[1]);
    struct ComplexNumber c;
    int i, j;
    for (j = 0; j < width; j++) {
        for (i = 0; i < width; i++) {
            c.real = 4.0 * i / width - 2.0;
            c.imaginary = 4.0 * j / width - 2.0;
            int mandelbrot = computeMandelbrot(c);
            if (mandelbrot == MAX_ITERATIONS) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}