//FormAI DATASET v1.0 Category: Fractal Generation ; Style: romantic
#include <stdio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

// Define the complex number structure
typedef struct {
    double real;
    double imag;
} complex;

// Add two complex numbers
complex add_complex(complex a, complex b) {
    complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

// Square a complex number
complex square_complex(complex a) {
    complex c;
    c.real = a.real * a.real - a.imag * a.imag;
    c.imag = 2*a.real*a.imag;
    return c;
}

// Calculate the absolute value of a complex number
double abs_complex(complex a) {
    return sqrt(a.real*a.real + a.imag*a.imag);
}

// Calculate the Mandelbrot set value for a given complex number
int mandelbrot(complex c) {
    complex z = {0,0};
    int i;
    for(i=0;i<MAX_ITER;i++) {
        z = add_complex(square_complex(z), c);
        if(abs_complex(z) > 2) {
            return i;
        }
    }
    return 0;
}

// This is the main function
int main() {
    FILE *fp;
    fp = fopen("output.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    int x, y;
    complex c;
    for(y=0;y<HEIGHT;y++) {
        for(x=0;x<WIDTH;x++) {
            c.real = (double)x / WIDTH * 4 - 2;
            c.imag = (double)y / HEIGHT * 4 - 2;
            int n = mandelbrot(c);
            fwrite(((unsigned char[]){n, n, n}), 1, 3, fp);
        }
    }
    fclose(fp);
    printf("Fractal generated!");
    return 0;
}