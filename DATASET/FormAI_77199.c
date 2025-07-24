//FormAI DATASET v1.0 Category: Fractal Generation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITERATIONS 50

typedef struct ComplexNumber {
    double real;
    double imaginary;
} ComplexNumber;

ComplexNumber add(ComplexNumber c1, ComplexNumber c2) {
    ComplexNumber result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

ComplexNumber multiply(ComplexNumber c1, ComplexNumber c2) {
    ComplexNumber result;
    result.real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary);
    result.imaginary = (c1.real * c2.imaginary) + (c1.imaginary * c2.real);
    return result;
}

bool isInside(ComplexNumber c) {
    ComplexNumber z = {0, 0};
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        z = add(multiply(z, z), c);
        if (sqrt(pow(z.real, 2) + pow(z.imaginary, 2)) > 2) {
            return false;
        }
    }
    return true;
}

int main() {
    unsigned char image[WIDTH][HEIGHT][3];
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            ComplexNumber c = {
                (4.0 * i / WIDTH) - 2,
                (4.0 * j / HEIGHT) - 2
            };
            if (isInside(c)) {
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }
            else {
                image[i][j][0] = 0;
                image[i][j][1] = 0;
                image[i][j][2] = 0;
            }
        }
    }
    FILE *file = fopen("fractal.bmp", "wb");
    fprintf(file, "P6 %d %d %d\n", WIDTH, HEIGHT, 255);
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            fwrite(image[i][j], sizeof(unsigned char), 3, file);
        }
    }
    fclose(file);
    return 0;
}