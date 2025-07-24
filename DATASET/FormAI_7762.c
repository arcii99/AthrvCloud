//FormAI DATASET v1.0 Category: Fractal Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ITERATIONS 100
#define WIDTH 100
#define HEIGHT 50

typedef struct _complex {
    double real;
    double imag;
} Complex;

void setPixel(char canvas[][WIDTH], int x, int y, char c) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = c;
    }
}

void plotFractal(char canvas[][WIDTH], Complex c) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Complex z = { x - WIDTH / 2, y - HEIGHT / 2 };
            int iter = 0;
            while (iter < MAX_ITERATIONS) {
                z = (Complex) { z.real * z.real - z.imag * z.imag + c.real, 2 * z.real * z.imag + c.imag };
                if (sqrt(z.real * z.real + z.imag * z.imag) > 2) {
                    break;
                }
                iter++;
            }
            setPixel(canvas, x, y, iter == MAX_ITERATIONS ? ' ' : iter % 10 + '0');
        }
    }
}

void drawCanvas(char canvas[][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(canvas[y][x]);
        }
        putchar('\n');
    }
}

int main() {
    char canvas[HEIGHT][WIDTH];
    memset(canvas, ' ', sizeof(canvas));
    Complex c = { -0.7, 0.4 };
    plotFractal(canvas, c);
    drawCanvas(canvas);
    return 0;
}