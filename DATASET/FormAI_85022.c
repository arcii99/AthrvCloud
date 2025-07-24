//FormAI DATASET v1.0 Category: Fractal Generation ; Style: ephemeral
#include <stdio.h>

/* This program generates a fractal using the escape time algorithm */
/* By changing the parameters, you can create different types of fractals */

#define WIDTH 100
#define HEIGHT 100
#define MAX_ITER 1000

int mandelbrot(double x, double y);

int main()
{
    int x, y, i;
    double cx, cy;
    
    /* Coordinates for the center of the fractal (change these as desired) */
    cx = -0.75;
    cy = 0;
    
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            i = mandelbrot(cx + (double)x / WIDTH * 4 - 2, cy + (double)y / HEIGHT * 4 - 2);
            if (i == MAX_ITER) {
                putchar(' ');
            } else {
                putchar('#');
            }
        }
        putchar('\n');
    }
}

int mandelbrot(double x, double y)
{
    int i;
    double zx, zy, zxsq, zysq, tmp;
    
    zx = 0;
    zy = 0;
    
    for (i = 0; i < MAX_ITER; i++) {
        zxsq = zx * zx;
        zysq = zy * zy;
        if (zxsq + zysq > 4) {
            break;
        }
        tmp = zxsq - zysq + x;
        zy = 2 * zx * zy + y;
        zx = tmp;
    }
    
    return i;
}