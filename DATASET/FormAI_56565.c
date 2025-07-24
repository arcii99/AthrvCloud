//FormAI DATASET v1.0 Category: Fractal Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 800

struct complex
{
    double real;
    double imag;
};

int fractal[WIDTH][HEIGHT]; // our fractal image

// define the coordinates of our zooming in and out
struct complex zoom_start = {-2, -2};
struct complex zoom_end = {2, 2};

double map(double value, double start1, double end1, double start2, double end2)
{
    return start2 + (end2 - start2) * ((value - start1) / (end1 - start1));
}

struct complex get_complex_from_point(int x, int y)
{
    struct complex c = { map(x, 0, WIDTH, zoom_start.real, zoom_end.real),
                         map(y, 0, HEIGHT, zoom_start.imag, zoom_end.imag) };
    return c;
}

int mandelbrot(struct complex c)
{
    struct complex z = {0, 0};
    int i;
    for (i = 0; i < 1000; i++)
    {
        double r = z.real * z.real - z.imag * z.imag + c.real;
        double i = 2 * z.real * z.imag + c.imag;
        z.real = r;
        z.imag = i;
        if (z.real * z.real + z.imag * z.imag > 4) break;
    }
    return i;
}

void generate_fractal()
{
    int x, y;
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            struct complex c = get_complex_from_point(x, y);
            int iter = mandelbrot(c);
            fractal[x][y] = iter;
        }
    }
}

void print_fractal()
{
    int x, y;
    FILE *fp = fopen("fractal.pgm", "w");
    fprintf(fp, "P2\n%d %d\n%d\n", WIDTH, HEIGHT, 255);
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            fprintf(fp, "%d ", fractal[x][y]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main()
{
    generate_fractal();
    print_fractal();
    return 0;
}