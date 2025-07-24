//FormAI DATASET v1.0 Category: Fractal Generation ; Style: safe
#include <stdio.h>

#define WIDTH 80
#define HEIGHT 50

void iterate(double *x, double *y, double *a, double *b)
{
    double new_x, new_y;
    new_x = *x * *x - *y * *y + *a;
    new_y = 2 * *x * *y + *b;
    *x = new_x;
    *y = new_y;
}

int get_iterations(double a, double b)
{
    double x = 0.0, y = 0.0;
    int iterations = 0;

    while (x * x + y * y <= 4 && iterations < 1000)
    {
        iterate(&x, &y, &a, &b);
        iterations++;
    }

    return iterations;
}

int main()
{
    int x, y, i;

    double a_min = -2.0;
    double a_max = 2.0;
    double b_min = -1.5;
    double b_max = 1.5;

    double a_inc = (a_max - a_min) / WIDTH;
    double b_inc = (b_max - b_min) / HEIGHT;

    for (y = 0; y < HEIGHT; ++y)
    {
        for (x = 0; x < WIDTH; ++x)
        {
            double a = a_min + x * a_inc;
            double b = b_min + y * b_inc;
            int iterations = get_iterations(a, b);
            char c = ' ';

            for (i = 0; i < iterations; ++i)
            {
                c = '*';
            }

            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}