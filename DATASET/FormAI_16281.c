//FormAI DATASET v1.0 Category: Fractal Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct complex
{
    double real;
    double imag;
} complex_t;

complex_t init_complex(double, double);
complex_t add_complex(complex_t, complex_t);
complex_t square_complex(complex_t);
int iterate_fractal(complex_t, int);
void plot_pixel(int, int, int, int, int);
void generate_fractal();

int main()
{
    generate_fractal();
    return 0;
}

complex_t init_complex(double r, double i)
{
    complex_t c;
    c.real = r;
    c.imag = i;
    return c;
}

complex_t add_complex(complex_t a, complex_t b)
{
    complex_t c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

complex_t square_complex(complex_t a)
{
    complex_t c;
    c.real = (a.real * a.real) - (a.imag * a.imag);
    c.imag = 2.0 * a.real * a.imag;
    return c;
}

int iterate_fractal(complex_t c, int max_iterations)
{
    complex_t z = init_complex(0.0, 0.0);
    int i;

    for (i = 0; i < max_iterations; i++)
    {
        z = add_complex(square_complex(z), c);
        if ((z.real * z.real) + (z.imag * z.imag) > 4.0)
        {
            return i;
        }
    }

    return 0;
}

void plot_pixel(int x, int y, int r, int g, int b)
{
    printf("drawPixel(%d, %d, %d, %d, %d);\n", x, y, r, g, b);
}

void generate_fractal()
{
    int x, y, iterations;
    double scale = 1.5;
    complex_t c;

    printf("canvas(%d, %d);\n", WIDTH, HEIGHT);

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            c = init_complex(((double)x - (WIDTH / 2.0)) * scale / ((double) WIDTH / 2.0), ((double)y - (HEIGHT / 2.0)) * scale / ((double) HEIGHT / 2.0));
            iterations = iterate_fractal(c, 1000);
            if (iterations == 0)
            {
                plot_pixel(x, y, 0, 0, 0);
            }
            else
            {
                plot_pixel(x, y, iterations % 256, (iterations * 6) % 256, (iterations * 12) % 256);
            }
        }
    }
}