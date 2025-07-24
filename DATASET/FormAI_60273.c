//FormAI DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct {
    double real;
    double imag;
} complex_t;

static inline double normalize(double value, double min, double max) {
    return (value - min) / (max - min);
}

static inline complex_t add(complex_t a, complex_t b) {
    return (complex_t){a.real + b.real, a.imag + b.imag};
}

static inline complex_t multiply(complex_t a, complex_t b) {
    return (complex_t){a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
}

static inline complex_t square(complex_t z) {
    return multiply(z, z);
}

static inline double mandelbrot(complex_t c, int max_iterations) {
    complex_t z = {0, 0};
    int i;
    for (i = 0; i < max_iterations; i++) {
        z = add(square(z), c);
        if (z.real * z.real + z.imag * z.imag > 4) {
            break;
        }
    }
    return normalize(i, 0, max_iterations);
}

static inline complex_t pixels_to_complex(int x, int y) {
    double real = normalize(x, 0, WIDTH) * 3.0 - 2.25;
    double imag = normalize(y, 0, HEIGHT) * 3.0 - 1.5;
    return (complex_t){real, imag};
}

int main(int argc, char *argv[]) {
    int max_iterations = 256;
    int x, y, i;
    double pixels[WIDTH * HEIGHT];

    // calculate mandelbrot set
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            complex_t c = pixels_to_complex(x, y);
            pixels[y * WIDTH + x] = mandelbrot(c, max_iterations);
        }
    }

    // generate fractal image
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d\n%d\n255\n", WIDTH, HEIGHT);
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            double value = pixels[y * WIDTH + x];
            unsigned char red = (unsigned char)(value * 255);
            unsigned char green = (unsigned char)(value * 0);
            unsigned char blue = (unsigned char)(value * 255);
            fwrite(&red, sizeof(unsigned char), 1, fp);
            fwrite(&green, sizeof(unsigned char), 1, fp);
            fwrite(&blue, sizeof(unsigned char), 1, fp);
        }
    }
    fclose(fp);

    return 0;
}