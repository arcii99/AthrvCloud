//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40

int mandelbrot(double x, double y) {
    int i;
    double re = x, im = y, new_re, new_im;
    for (i = 0; i < 1000; i++) {
        new_re = (re * re) - (im * im) + x;
        new_im = (2 * re * im) + y;
        if ((new_re * new_re) + (new_im * new_im) > 4)
            break;
        re = new_re;
        im = new_im;
    }
    return i;
}

int main() {
    double x, y;
    int i, j, val;
    for (y = -1.0; y <= 1.0; y += 2.0 / HEIGHT) {
        for (x = -2.0; x <= 1.0; x += 3.0 / WIDTH) {
            val = mandelbrot(x, y);
            if (val == 1000) 
                printf("%c", ' ');
            else
                printf("%c", (char) (val % 26 + 'a'));
        }
        printf("\n");
    }
    return 0;
}