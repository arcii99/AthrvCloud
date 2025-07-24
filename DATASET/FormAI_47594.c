//FormAI DATASET v1.0 Category: Fractal Generation ; Style: realistic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_ITERATIONS 500

int mandelbrot(double x, double y) { // Determine if point (x,y) is in the Mandelbrot set
    double real = x;
    double imag = y;
    int iterations = 0;
    while (pow(real, 2) + pow(imag, 2) < 4 && iterations < MAX_ITERATIONS) {
        double r = pow(real, 2) - pow(imag, 2) + x;
        double i = 2*real*imag + y;
        real = r;
        imag = i;
        iterations++;
    }
    if (iterations == MAX_ITERATIONS) {
        return 0;
    } else {
        return iterations;
    }
}

int main() {
    srand(time(NULL));
    int fractal[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            double x = ((double)i - WIDTH/2.0) * 4.0/WIDTH;
            double y = ((double)j - HEIGHT/2.0) * 4.0/HEIGHT;
            fractal[i][j] = mandelbrot(x, y);
        }
    }
    printf("\n\n");
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            if (fractal[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}