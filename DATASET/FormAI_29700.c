//FormAI DATASET v1.0 Category: Fractal Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 40
#define ITERATIONS 50
#define THRESHOLD 2.0

typedef struct {
    double real;
    double imaginary;
} Complex;

void initFractal(int *fractal);
void updateFractal(int *fractal, int iteration);
void printFractal(int *fractal);
Complex getPixelValue(int x, int y);
int mandelbrotSet(Complex c);

int main() {
    int fractal[WIDTH * HEIGHT];
    srand(time(NULL));
    initFractal(fractal);
    for (int iteration = 0; iteration < ITERATIONS; iteration++) {
        updateFractal(fractal, iteration);
        printFractal(fractal);
    }
    return 0;
}

void initFractal(int *fractal) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        fractal[i] = 0;
    }
}

void updateFractal(int *fractal, int iteration) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            if (fractal[y * WIDTH + x] == 0) {
                Complex c = getPixelValue(x, y);
                int isInSet = mandelbrotSet(c);
                if (isInSet) {
                    fractal[y * WIDTH + x] = iteration;
                }
            }
        }
    }
}

void printFractal(int *fractal) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (fractal[y * WIDTH + x] == 0) {
                printf(" ");
            } else {
                printf("%c", 33 + fractal[y * WIDTH + x] % 94);
            }
        }
        printf("\n");
    }
}

Complex getPixelValue(int x, int y) {
    double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
    double imaginary = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
    return (Complex) {real, imaginary};
}

int mandelbrotSet(Complex c) {
    Complex z = (Complex) {0.0, 0.0};
    int i;
    for (i = 0; i < ITERATIONS; i++) {
        double real = z.real * z.real - z.imaginary * z.imaginary + c.real;
        double imaginary = 2 * z.real * z.imaginary + c.imaginary;
        z.real = real;
        z.imaginary = imaginary;
        if (z.real * z.real + z.imaginary * z.imaginary > THRESHOLD * THRESHOLD) {
            break;
        }
    }
    return i == ITERATIONS;
}