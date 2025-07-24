//FormAI DATASET v1.0 Category: Fractal Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 200

// structure to represent complex number
typedef struct {
    double real;
    double imaginary;
} complex;

// function to calculate the modulus of a complex number
double modulus(complex c) {
    return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}

// function to perform complex multiplication
complex multiply(complex a, complex b) {
    complex result;
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + b.real * a.imaginary;
    return result;
}

// function to perform complex addition
complex add(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

// function to check if a complex number is in the Mandelbrot set
bool inMandelbrotSet(complex c) {
    complex z = {0.0, 0.0};
    int iter = 0;
    while (modulus(z) < 2 && iter < MAX_ITER) {
        z = add(multiply(z, z), c);
        iter++;
    }
    return iter == MAX_ITER;
}

// function to generate the Mandelbrot set
void generateMandelbrotSet(unsigned char* image) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // calculate the complex number corresponding to the pixel
            complex c;
            c.real = ((double) x - WIDTH / 2) / (WIDTH / 4);
            c.imaginary = ((double) y - HEIGHT / 2) / (HEIGHT / 4);

            // check if the complex number is in the Mandelbrot set
            if (inMandelbrotSet(c)) {
                image[3 * (y * WIDTH + x)] = 0;
                image[3 * (y * WIDTH + x) + 1] = 0;
                image[3 * (y * WIDTH + x) + 2] = 0;
            } else {
                int iter = 0;
                complex z = {0.0, 0.0};
                while (modulus(z) < 2 && iter < MAX_ITER) {
                    z = add(multiply(z, z), c);
                    iter++;
                }
                double smoothIter = iter;
                for (int i = 0; i < 3; i++) {
                    image[3 * (y * WIDTH + x) + i] = (unsigned char) (smoothIter / MAX_ITER * 255);
                }
            }
        }
    }
}

int main() {
    unsigned char image[WIDTH * HEIGHT * 3];
    generateMandelbrotSet(image);
    FILE* fp = fopen("mandelbrot.ppm", "wb");
    fprintf(fp, "P6 %d %d 255\n", WIDTH, HEIGHT);
    fwrite(image, 1, sizeof(image), fp);
    fclose(fp);
    return 0;
}