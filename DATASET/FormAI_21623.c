//FormAI DATASET v1.0 Category: Fractal Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000 

typedef unsigned char byte;

int main() {
    int x, y, iter;
    double complex z, c;
    double zx, zy, cx, cy, dx, dy;
    dx = 4.0 / WIDTH;
    dy = 4.0 / HEIGHT;
    byte* pixels = (byte*) malloc(WIDTH * HEIGHT * sizeof(byte)); 
    FILE* file = fopen("fractal.pgm", "wb");
    if (file == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }
    fprintf(file, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    for (y = 0; y < HEIGHT; ++y) {
        cy = (y * dy) - 2.0;
        for (x = 0; x < WIDTH; ++x) {
            cx = (x * dx) - 2.0;
            z = cx + cy * I;
            c = z;
            for (iter = 0; iter < MAX_ITER && cabs(z) < 2.0; ++iter) {
                z = z * z + c;
            }
            pixels[y * WIDTH + x] = iter % 256;
        }
    }
    fwrite(pixels, sizeof(byte), WIDTH * HEIGHT, file);
    fclose(file);
    free(pixels);
    return 0;
}