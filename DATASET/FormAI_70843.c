//FormAI DATASET v1.0 Category: Fractal Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_ITERATIONS 100

void create_fractal(double complex point);
int iterations_needed(double complex c);

int image[WIDTH][HEIGHT];

int main() {
    int i, j;
    double complex point;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            point = ((double)i - WIDTH/2)/(double)WIDTH +
                     (((double)j - HEIGHT/2)/(double)HEIGHT)*I;
            create_fractal(point);
        }
    }

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (image[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}

void create_fractal(double complex point) {
    int iterations = iterations_needed(point);
    if (iterations == MAX_ITERATIONS) {
        image[(int)creal(point)*WIDTH + WIDTH/2][(int)cimag(point)*HEIGHT + HEIGHT/2] = 0;
    } else {
        image[(int)creal(point)*WIDTH + WIDTH/2][(int)cimag(point)*HEIGHT + HEIGHT/2] = 1;
    }
}

int iterations_needed(double complex c) {
    int i;
    double complex z = 0;

    for (i = 0; i < MAX_ITERATIONS; i++) {
        z = z*z + c;

        if (cabs(z) > 2.0) {
            return i;
        }
    }

    return MAX_ITERATIONS;
}