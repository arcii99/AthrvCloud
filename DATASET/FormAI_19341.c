//FormAI DATASET v1.0 Category: Fractal Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000

typedef struct Color {
    int r;
    int g;
    int b;
} Color;

// function prototypes
int mandelbrot(int x, int y);
Color getColor(int iterations);

int main() {
    FILE *file;
    char *filename = "fractal.ppm";

    file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    // generate fractal
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            int iterations = mandelbrot(x, y);
            Color color = getColor(iterations);
            fputc(color.r, file);
            fputc(color.g, file);
            fputc(color.b, file);
        }
    }

    fclose(file);
    printf("Fractal generated and saved to %s\n", filename);

    return 0;
}

int mandelbrot(int x, int y) {
    double zx = 0;
    double zy = 0;
    double cx = (double)x / WIDTH * 3.5 - 2.5;
    double cy = (double)y / HEIGHT * 2 - 1;

    for(int i = 0; i < MAX_ITERATIONS; i++) {
        double zx_new = zx * zx - zy * zy + cx;
        double zy_new = 2 * zx * zy + cy;
        zx = zx_new;
        zy = zy_new;

        if(zx * zx + zy * zy > 4) {
            return i;
        }
    }

    return MAX_ITERATIONS;
}

Color getColor(int iterations) {
    Color color;

    // black if in set
    if(iterations == MAX_ITERATIONS) {
        color.r = 0;
        color.g = 0;
        color.b = 0;
        return color;
    }

    // alternate color scheme
    int c = iterations % 8;

    switch(c) {
        case 0:
            color.r = 66;
            color.g = 30;
            color.b = 15;
            break;
        case 1:
            color.r = 25;
            color.g = 7;
            color.b = 26;
            break;
        case 2:
            color.r = 9;
            color.g = 1;
            color.b = 47;
            break;
        case 3:
            color.r = 4;
            color.g = 4;
            color.b = 73;
            break;
        case 4:
            color.r = 0;
            color.g = 7;
            color.b = 100;
            break;
        case 5:
            color.r = 12;
            color.g = 44;
            color.b = 138;
            break;
        case 6:
            color.r = 24;
            color.g = 82;
            color.b = 177;
            break;
        case 7:
            color.r = 57;
            color.g = 125;
            color.b = 209;
            break;
    }

    return color;
}