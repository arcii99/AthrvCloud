//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define WIDTH 80
#define HEIGHT 40

#define MAX_ITERATIONS 100

int mandelbrot(int x, int y) {
    double real = (double)x / WIDTH * 4.0 - 2.5;
    double imag = (double)y / HEIGHT * 4.0 - 2.0;

    double zReal = 0.0, zImag = 0.0;
    int iteration = 0;

    while (zReal * zReal + zImag * zImag < 4.0 && iteration < MAX_ITERATIONS) {
        double zRealPrime = zReal * zReal - zImag * zImag + real;
        double zImagPrime = 2.0 * zReal * zImag + imag;
        zReal = zRealPrime;
        zImag = zImagPrime;
        iteration++;
    }

    return iteration;
}

int main() {
    char screen[HEIGHT][WIDTH];

    // Initialize screen buffer
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            screen[y][x] = ' ';
        }
    }

    // Generate fractal
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int iteration = mandelbrot(x, y);
            if (iteration == MAX_ITERATIONS) {
                screen[y][x] = '.';
            } else {
                screen[y][x] = 'A' + (iteration % 26);
            }
        }
    }

    // Render fractal
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(screen[y][x]);
        }
        putchar('\n');
    }

    return 0;
}