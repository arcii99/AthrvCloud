//FormAI DATASET v1.0 Category: Fractal Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 50
#define HEIGHT 50

int mandelbrot(double x, double y) {
    double prev_real = 0;
    double prev_imag = 0;
    double curr_real = 0;
    double curr_imag = 0;

    int i;
    for(i = 0; i < 1000; i++) {
        prev_real = curr_real;
        prev_imag = curr_imag;

        curr_real = prev_real * prev_real - prev_imag * prev_imag + x;
        curr_imag = 2 * prev_real * prev_imag + y;

        if((curr_real * curr_real + curr_imag * curr_imag) > 4) return i;
    }

    return 1000;
}

int main() {
    int i, j;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            double x = (j - WIDTH / 2.0) * 4.0 / WIDTH;
            double y = (i - HEIGHT / 2.0) * 4.0 / HEIGHT;

            int iterations = mandelbrot(x, y);
            if(iterations < 1000) {
                putchar(iterations % 10 + '0');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}