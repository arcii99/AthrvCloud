//FormAI DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_ITER 10000
#define MAX_WIDTH 150
#define MAX_HEIGHT 30
#define MIN_X -2
#define MAX_X 1
#define MIN_Y -1
#define MAX_Y 1

typedef struct s_complex {
    double real;
    double imag;
} complex;

typedef struct s_point {
    int x;
    int y;
} point;

/* Functions to calculate complex arithmetic operations */
complex add_complex(complex a, complex b) {
    return (complex){a.real + b.real, a.imag + b.imag};
}

complex multiply_complex(complex a, complex b) {
    return (complex){a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
}

double abs_complex(complex a) {
    return sqrt(a.real * a.real + a.imag * a.imag);
}

/* Function to check if a point is in the Mandelbrot set */
bool is_in_mandelbrot_set(complex c) {
    complex z = {0.0, 0.0};
    int i;
    for (i = 0; i < MAX_ITER; i++) {
        z = add_complex(multiply_complex(z, z), c);
        if (abs_complex(z) > 2) {
            return false;
        }
    }
    return true;
}

/* Function to convert a point (x,y) to a complex number */
complex point_to_complex(point p, point screen) {
    double real = ((double)p.x / screen.x) * (MAX_X - MIN_X) + MIN_X;
    double imag = ((double)p.y / screen.y) * (MAX_Y - MIN_Y) + MIN_Y;
    return (complex){real, imag};
}

/* Function to print the Mandelbrot set to the console */
void print_mandelbrot(int width, int height) {
    point screen = {width, height};
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            point p = {x, y};
            complex c = point_to_complex(p, screen);
            if (is_in_mandelbrot_set(c)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    print_mandelbrot(MAX_WIDTH, MAX_HEIGHT);
    return 0;
}