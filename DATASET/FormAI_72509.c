//FormAI DATASET v1.0 Category: Fractal Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 160
#define HEIGHT 60
#define MAX_ITER 50

bool is_in_fractal(double real, double imag) {
    double complex c = real + imag * I;
    double complex z = 0 + 0 * I;
    for (int i = 0; i < MAX_ITER; i++) {
        z = z * z + c;
        if (cabs(z) > 2) {
            return false;
        }
    }
    return true;
}

void draw_fractal(double min_real, double max_real, double min_imag, double max_imag) {
    double scale_real = (max_real - min_real) / (double) WIDTH;
    double scale_imag = (max_imag - min_imag) / (double) HEIGHT;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = min_real + scale_real * x;
            double imag = max_imag - scale_imag * y;

            if (is_in_fractal(real, imag)) {
                putchar('#');
            }
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL));
    double real_center = (double) rand() / RAND_MAX * 4 - 2;
    double imag_center = (double) rand() / RAND_MAX * 4 - 2;
    double zoom = (double) rand() / RAND_MAX * 2 + 1;

    double min_real = real_center - zoom;
    double max_real = real_center + zoom;
    double min_imag = imag_center - zoom;
    double max_imag = imag_center + zoom;

    draw_fractal(min_real, max_real, min_imag, max_imag);

    return 0;
}