//FormAI DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct
{
    double x;
    double y;
} Complex;

unsigned char img[WIDTH][HEIGHT][3]; // 3D array to store RGB pixel data

Complex complex_add(Complex a, Complex b)
{
    Complex c = {a.x + b.x, a.y + b.y};
    return c;
}

Complex complex_square(Complex a)
{
    Complex c = {a.x * a.x - a.y * a.y, 2 * a.x * a.y};
    return c;
}

double complex_magnitude(Complex a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

bool is_in_mandelbrot_set(Complex c, int max_iterations)
{
    Complex z = {0, 0};
    int iterations = 0;
    while (complex_magnitude(z) <= 2 && iterations < max_iterations)
    {
        z = complex_add(complex_square(z), c);
        iterations++;
    }
    return iterations == max_iterations;
}

void generate_fractal(int max_iterations)
{
    Complex c;
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            c.x = (4.0 * i / WIDTH - 2);
            c.y = (4.0 * j / HEIGHT - 2);
            if (is_in_mandelbrot_set(c, max_iterations))
            {
                img[i][j][0] = 255;
                img[i][j][1] = 255;
                img[i][j][2] = 255;
            }
            else
            {
                img[i][j][0] = 0;
                img[i][j][1] = 0;
                img[i][j][2] = 0;
            }
        }
    }
}

void save_image()
{
    FILE *f;
    char filename[50];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(filename, sizeof(filename), "fractal_%Y%m%d%H%M%S.ppm", tm);
    f = fopen(filename, "wb");
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            fwrite(img[i][j], 1, 3, f);
        }
    }
    fclose(f);
}

int main()
{
    memset(img, 0, sizeof(img)); // initialize image to all black
    generate_fractal(1000);
    save_image();
    printf("File saved.\n");
    return 0;
}