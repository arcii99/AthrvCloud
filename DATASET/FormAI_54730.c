//FormAI DATASET v1.0 Category: Fractal Generation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_DEPTH 8

typedef struct {
    double x;
    double y;
} Complex;

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGB;

RGB color(int iteration) {
    RGB c;
    if (iteration == MAX_DEPTH) {
        c.r = 0;
        c.g = 0;
        c.b = 0;
    } else {
        c.r = iteration % 256;
        c.g = (iteration * 7) % 256;
        c.b = (iteration * 13) % 256;
    }
    return c;
}

int mandelbrot(Complex c) {
    Complex z;
    z.x = 0.0;
    z.y = 0.0;
    int iteration = 0;
    double temp;
    while (z.x*z.x + z.y*z.y < 4.0 && iteration < MAX_DEPTH) {
        temp = z.x*z.x - z.y*z.y + c.x;
        z.y = 2*z.x*z.y + c.y;
        z.x = temp;
        iteration++;
    }
    return iteration;
}

void draw_fractal(RGB image[WIDTH][HEIGHT], Complex center, double zoom) {
    int x, y;
    double real, imag;
    Complex c;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            real = ((double) x - 0.5 * WIDTH) / (0.5 * zoom * WIDTH) + center.x;
            imag = ((double) y - 0.5 * HEIGHT) / (0.5 * zoom * HEIGHT) + center.y;
            c.x = real;
            c.y = imag;
            image[x][y] = color(mandelbrot(c));
        }
    }
}

void write_to_ppm_file(RGB image[WIDTH][HEIGHT], char *filename) {
    FILE *f = fopen(filename, "wb");
    fprintf(f, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            fwrite(&image[x][y], 1, 3, f);
        }
    }
    fclose(f);
}

int main() {
    srand(time(NULL));
    double x = ((double) rand() / RAND_MAX) * 4 - 2;
    double y = ((double) rand() / RAND_MAX) * 4 - 2;
    Complex center = { x, y };
    double zoom = 1.0;
    
    RGB image[WIDTH][HEIGHT];
    draw_fractal(image, center, zoom);
    
    char filename[20];
    sprintf(filename, "fractal-%d.ppm", time(NULL));
    write_to_ppm_file(image, filename);
    
    return 0;
}