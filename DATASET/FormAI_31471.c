//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 80
#define MAX_ITER 100

typedef struct complex {
    double real;
    double imag;
} complex;

void set_pixel(char screen[HEIGHT][WIDTH], int row, int col, char c) {
    if (row < 0 || row >= HEIGHT) {
        return;
    }

    if (col < 0 || col >= WIDTH) {
        return;
    }

    screen[row][col] = c;
}

bool mandelbrot_test(complex c) {
    complex z = c;
    for (int i = 0; i < MAX_ITER; i++) {
        z = (complex) {
            z.real * z.real - z.imag * z.imag + c.real,
            2 * z.real * z.imag + c.imag
        };

        if (z.real * z.real + z.imag * z.imag > 4) {
            return false;
        }
    }

    return true;
}

int main() {
    char screen[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            complex c = {
                (double) (j - WIDTH / 2) / (WIDTH / 4),
                (double) (i - HEIGHT / 2) / (HEIGHT / 4)
            };

            if (mandelbrot_test(c)) {
                set_pixel(screen, i, j, '#');
            } else {
                set_pixel(screen, i, j, '.');
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(screen[i][j]);
        }

        putchar('\n');
    }

    return 0;
}