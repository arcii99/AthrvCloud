//FormAI DATASET v1.0 Category: Fractal Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

// Create a color struct to handle RGB values
typedef struct {
    int r, g, b;
} Color;

// Define the complex number struct
typedef struct {
    double re, im;
} Complex;

// Define the fractal function
int mandelbrot(Complex c) {
    Complex z = {0, 0};
    int i;
    
    for (i = 0; i < 256; i++) {
        if (z.re * z.re + z.im * z.im > 4.0) {
            return i;
        }
        Complex temp = {z.re*z.re - z.im*z.im, z.re*z.im*2};
        z.re = temp.re + c.re;
        z.im = temp.im + c.im;
    }
    
    return 255;
}

int main() {
    // Create the image buffer
    Color image[WIDTH][HEIGHT];
    
    // Loop through each pixel and calculate the corresponding mandelbrot value
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
            Complex c = {real, imag};
            int mand = mandelbrot(c);
            image[x][y].r = mand;
            image[x][y].g = mand;
            image[x][y].b = mand;
        }
    }
    
    // Write the image to a file
    FILE *fp;
    fp = fopen("mandelbrot.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fputc(image[x][y].r, fp);
            fputc(image[x][y].g, fp);
            fputc(image[x][y].b, fp);
        }
    }
    fclose(fp);
    
    return 0;
}