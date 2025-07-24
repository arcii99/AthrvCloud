//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// define constants
#define WIDTH 80
#define HEIGHT 24
#define MAX_ITER 50
#define MIN_X -2.5
#define MAX_X 1.5
#define MIN_Y -1
#define MAX_Y 1

// define structs
typedef struct {
    double real;
    double imag;
} ComplexNumber;

// define functions
void generateFractal(ComplexNumber z, ComplexNumber c, int iterations, int *output) {
    int i;
    for (i = 0; i < iterations; i++) {
        if (z.real * z.real + z.imag * z.imag > 4) {
            break;
        }
        double real_part = z.real;
        z.real = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * real_part * z.imag + c.imag;
    }
    *output = i;
}

int main() {
    int fractal[WIDTH][HEIGHT];
    double x_increment = (MAX_X - MIN_X) / WIDTH;
    double y_increment = (MAX_Y - MIN_Y) / HEIGHT;
    ComplexNumber z, c;
    int i, j, num_iterations;

    // initialize random seed
    srand(time(NULL));

    // generate fractal
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            z.real = 0;
            z.imag = 0;
            c.real = MIN_X + i * x_increment;
            c.imag = MIN_Y + j * y_increment;
            generateFractal(z, c, MAX_ITER, &num_iterations);
            fractal[i][j] = num_iterations;
        }
    }

    // print fractal
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            if (fractal[i][j] < 10) {
                printf(".");
            } else if (fractal[i][j] < 20) {
                printf("*");
            } else if (fractal[i][j] < 30) {
                printf("+");
            } else if (fractal[i][j] < 40) {
                printf("-");
            } else if (fractal[i][j] < 50) {
                printf("=");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // exit program
    return 0;
}