//FormAI DATASET v1.0 Category: Fractal Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 50
#define MAX_ITER 100
#define BAILOUT 16.0

// Helper function that returns the iteration count for a given point in the complex plane
int get_iter_count(double x, double y) {
    double real = 0.0, imag = 0.0;
    int iter_count = 0;
    while (real*real + imag*imag <= BAILOUT*BAILOUT && iter_count < MAX_ITER) {
        double new_real = real*real - imag*imag + x;
        double new_imag = 2*real*imag + y;
        real = new_real;
        imag = new_imag;
        iter_count++;
    }
    return iter_count;
}

// Main function that generates the fractal and prints it to the console
void generate_fractal() {
    char pixels[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = ((double)x - WIDTH/2) * 4.0 / WIDTH; // Map x to [-2, 2]
            double imag = ((double)y - HEIGHT/2) * 4.0 / WIDTH; // Map y to [-2, 2]
            int iter_count = get_iter_count(real, imag);
            if (iter_count == MAX_ITER) {
                pixels[y][x] = ' ';
            } else {
                pixels[y][x] = (iter_count % 10) + '0';
            }
        }
    }
    printf("\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", pixels[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

// Entry point of the program
int main() {
    printf("Welcome to the C Fractal Generator!\n\n");
    printf("This program generates a Mandelbrot fractal and prints it to the console.\n");
    printf("Press Enter to continue...\n\n");
    getchar();
    generate_fractal();
    return 0;
}