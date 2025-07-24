//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Cryptic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct Complex {
    double real; 
    double imag; 
} Complex;

int mandel(Complex c);

int main() {
    int x, y, i, j; 
    double midX = -0.75, midY = 0;
    double scale = 2.5 / WIDTH;
    FILE *imageFile; 
    char *filename = "image.ppm"; 

    imageFile = fopen(filename, "wb");
    fprintf(imageFile, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    Complex c, z; 
    int val; 

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            c.real = (double)(x - WIDTH / 2) * scale + midX;
            c.imag = (double)(y - HEIGHT / 2) * scale + midY;

            val = mandel(c);

            fputc(val % 256, imageFile); // red
            fputc(val % 256, imageFile); // green
            fputc(val % 256, imageFile); // blue
        }
    }

    fclose(imageFile); 
    return 0; 
}

int mandel(Complex c) {
    Complex z = { 0, 0 }; 
    int i; 

    for (i = 0; i < 256; i++) {
        if (sqrt(z.real * z.real + z.imag * z.imag) > 2) {
            break; 
        }

        Complex temp = { z.real, z.imag }; 

        z.real = temp.real * temp.real - temp.imag * temp.imag + c.real; 
        z.imag = 2 * temp.real * temp.imag + c.imag; 
    }

    return i; 
}