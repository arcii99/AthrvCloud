//FormAI DATASET v1.0 Category: Fractal Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define WIDTH 512
#define HEIGHT 512

struct complex {
    double real;
    double imag;
};

struct complex add(struct complex a, struct complex b) {
    struct complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

struct complex multiply(struct complex a, struct complex b) {
    struct complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

double modulus(struct complex z) {
    return sqrt(z.real * z.real + z.imag * z.imag);
}

void fractal(int iterations, int pixels[WIDTH][HEIGHT]) {
    struct complex z, c;
    int i, j, k;

    for (i = 0; i < WIDTH; ++i)
        for (j = 0; j < HEIGHT; ++j) {
            z = (struct complex){(i-WIDTH/2.0)/(WIDTH/4.0),
                (j-HEIGHT/2.0)/(WIDTH/4.0)};
            c = (struct complex){0.0, 0.0};
            k = 0;
            while (modulus(z) < 2.0 && k < iterations) {
                z = add(multiply(z, z), c);
                ++k;
            }
            pixels[i][j] = k*(255/iterations);
        }
}

int main() {
    int pixels[WIDTH][HEIGHT];
    fractal(100, pixels);
    FILE *fp;
    fp = fopen("fractal.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", WIDTH, HEIGHT, 255);
    fwrite(pixels, sizeof(pixels), 1, fp);
    fclose(fp);
    printf("Fractal generated successfully!\n");
    return 0;
}