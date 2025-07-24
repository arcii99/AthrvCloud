//FormAI DATASET v1.0 Category: Fractal Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_ITERATIONS 1000

void set_pixel(int x, int y, int color);
int mandelbrot(double x, double y);

int main()
{
    int i, j, color;
    double x, y;

    for(i = 0; i < WIDTH; i++)
    {
        for(j = 0; j < HEIGHT; j++)
        {
            x = ((double)i - WIDTH/2.0) * 4.0/WIDTH;
            y = ((double)j - HEIGHT/2.0) * 4.0/HEIGHT;
            color = mandelbrot(x, y) * 255 / MAX_ITERATIONS;
            set_pixel(i, j, color);
        }
    }
    return 0;
}

void set_pixel(int x, int y, int color)
{
    printf("\033[%d;%dH\033[48;5;%dm ", y + 1, x + 1, color);
}

int mandelbrot(double x, double y)
{
    int i;
    double a, b, tmp;

    a = 0.0;
    b = 0.0;

    for(i = 0; i < MAX_ITERATIONS; i++)
    {
        tmp = a;
        a = a*a - b*b + x;
        b = 2*tmp*b + y;

        if(a*a + b*b > 4.0) break;
    }
    return i;
}