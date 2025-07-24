//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Dennis Ritchie
#include <stdio.h>

#define WIDTH 80
#define HEIGHT 40
#define ITER 512

int mandelbrot(double real, double imag)
{
    double r = real, i = imag;
    int it, c = 0;
    for (it = 0; it < ITER; it++)
    {
        double rr = r * r, ii = i * i;
        if (rr + ii > 4.0) break;
        double rnew = rr - ii + real;
        i = 2.0 * r * i + imag;
        r = rnew;
        c++;
    }
    return c;
}

void print_fractal()
{
    double x, y;
    int i, j, iter, c;
    for (j = 0; j < HEIGHT; j++)
    {
        for (i = 0; i < WIDTH; i++)
        {
            x = (double)i / WIDTH * 4.0 - 2.0;
            y = (double)j / HEIGHT * 4.0 - 2.0;
            iter = mandelbrot(x, y);
            c = iter % 16;
            putchar(".-:=+*wgh%@"[c]);
        }
        putchar('\n');
    }
}

int main()
{
    print_fractal();
    return 0;
}