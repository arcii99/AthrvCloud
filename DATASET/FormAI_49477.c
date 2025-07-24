//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

void draw_fractal(int width, int height, double zoom, double complex center) {
    double complex c, z, temp;
    int i, j, iterations;
    char *pixels = malloc(width * height);

    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            c = center + (2.4/zoom) * ((i - width/2) / (double)width + (j-height/2) / (double)height * I);
            z = 0 + 0*I;
            iterations = 0;

            while(cabs(z) < 2 && iterations < 255) {
                temp = z;
                z = z*z + c;
                iterations++;
            }

            pixels[j*width + i] = 255 - iterations;
        }
    }

    for(j = 0; j < height; j++) {
        for(i = 0; i < width; i++) {
            printf("%c ", (pixels[j*width + i] < 128) ? '#' : ' ');
        }
        printf("\n");
    }

    free(pixels);
}

int main(int argc, char** argv) {
    int width = 80;
    int height = 30;
    double zoom = 1.0;
    double complex center = 0.0 + 0.0*I;

    draw_fractal(width, height, zoom, center);
    return 0;
}