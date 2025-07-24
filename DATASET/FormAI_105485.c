//FormAI DATASET v1.0 Category: Fractal Generation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ITER 1000

bool is_fractal(int x, int y) {
    double real = ((double) x / WIDTH) * 3.0 - 2.0;
    double imag = ((double) y / HEIGHT) * 2.0 - 1.0;
    double z_real = 0.0, z_imag = 0.0;

    for (int i = 0; i < MAX_ITER; i++) {
        double temp = z_real;
        z_real = z_real * z_real - z_imag * z_imag + real;
        z_imag = 2 * temp * z_imag + imag;

        if (sqrt(z_real * z_real + z_imag * z_imag) > 2.0) {
            return false;
        }
    }

    return true;
}

void draw_fractal() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (is_fractal(x, y)) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main() {
    draw_fractal();
    return 0;
}