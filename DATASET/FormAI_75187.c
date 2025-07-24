//FormAI DATASET v1.0 Category: Fractal Generation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// define constants
#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

// define a complex number struct
typedef struct complex_num {
    double real;
    double imag;
} ComplexNum;

// define global variables
int pixels[WIDTH][HEIGHT];

// function to compute the mandelbrot set
int computeMandelbrot(ComplexNum c) {
    ComplexNum z;
    z.real = 0;
    z.imag = 0;
    int i;
    for (i = 0; i < MAX_ITERATIONS; i++) {
        double z_real_squared = z.real * z.real;
        double z_imag_squared = z.imag * z.imag;
        if (z_real_squared + z_imag_squared > 4.0) {
            return i;
        }
        double new_real = z_real_squared - z_imag_squared + c.real;
        double new_imag = 2.0 * z.real * z.imag + c.imag;
        z.real = new_real;
        z.imag = new_imag;
    }
    return MAX_ITERATIONS;
}

// function to generate the fractal
void generateFractal() {
    double zoom = 1.0;
    double move_x = 0.0;
    double move_y = 0.0;
    int x;
    for (x = 0; x < WIDTH; x++) {
        int y;
        for (y = 0; y < HEIGHT; y++) {
            double real = (double)x / (double)WIDTH * 4.0 - 2.0;
            double imag = (double)y / (double)HEIGHT * 4.0 - 2.0;
            real /= zoom;
            imag /= zoom;
            real += move_x;
            imag += move_y;
            ComplexNum c = {real, imag};
            int iterations = computeMandelbrot(c);
            pixels[x][y] = iterations;
        }
    }
}

// function to print the fractal to a file
void printFractal() {
    char filename[100] = "fractal.pgm";
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("ERROR: Failed to open file.\n");
        return;
    }
    fprintf(file, "P5\n");
    fprintf(file, "%d %d\n", WIDTH, HEIGHT);
    fprintf(file, "%d\n", MAX_ITERATIONS);
    int x;
    for (x = 0; x < WIDTH; x++) {
        int y;
        for (y = 0; y < HEIGHT; y++) {
            fprintf(file, "%c", (char)(255 * ((double)pixels[x][y] / (double)MAX_ITERATIONS)));
        }
    }
    fclose(file);
    printf("Fractal generated successfully!\n");
}

int main() {
    generateFractal();
    printFractal();
    return 0;
}