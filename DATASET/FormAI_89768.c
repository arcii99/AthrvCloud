//FormAI DATASET v1.0 Category: Fractal Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ITER 100000
#define WIDTH 800
#define HEIGHT 800

typedef struct
{
    double real;
    double imag;
} Complex;

Complex addComplex(Complex c1, Complex c2)
{
    Complex result = {c1.real + c2.real, c1.imag + c2.imag};
    return result;
}

Complex multiplyComplex(Complex c1, Complex c2)
{
    Complex result = {c1.real * c2.real - c1.imag * c2.imag,
                      c1.real * c2.imag + c2.real * c1.imag};
    return result;
}

double modulus(Complex c)
{
    return sqrt(c.real * c.real + c.imag * c.imag);
}

bool isInside(Complex c)
{
    Complex zn = {0.0, 0.0};
    int i = 0;
    while (modulus(zn) < 2.0 && i < MAX_ITER)
    {
        zn = addComplex(multiplyComplex(zn, zn), c);
        i++;
    }
    return i == MAX_ITER;
}

void generateJuliaSet()
{
    double x_min = -2.0;
    double x_max = 2.0;
    double y_min = -2.0;
    double y_max = 2.0;

    double x_step = (x_max - x_min) / (double)WIDTH;
    double y_step = (y_max - y_min) / (double)HEIGHT;

    Complex c = {-0.8, 0.156};

    FILE *fp = fopen("julia_set.ppm", "w");
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
    fprintf(fp, "255\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            Complex z = {x_min + j * x_step, y_max - i * y_step};

            if (isInside(z))
            {
                fprintf(fp, "0 0 0 ");
            }
            else
            {
                fprintf(fp, "255 255 255 ");
            }
        }
    }

    fclose(fp);
}

int main()
{
    generateJuliaSet();
    return 0;
}