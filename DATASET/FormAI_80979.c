//FormAI DATASET v1.0 Category: Fractal Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 500
#define WIDTH 800
#define HEIGHT 800
#define X_MIN -2
#define X_MAX 2
#define Y_MIN -2
#define Y_MAX 2

void set_pixel(unsigned char *buffer, int x, int y, unsigned char red, unsigned char green, unsigned char blue) {
    int offset = (y * WIDTH + x) * 3;
    buffer[offset] = red;
    buffer[offset + 1] = green;
    buffer[offset + 2] = blue;
}

void draw_fractal(unsigned char *buffer) {
    double x0, y0, x, y, x_tmp;
    int iterations;
    double real, imag;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            x0 = (((double) i) / WIDTH) * (X_MAX - X_MIN) + X_MIN;
            y0 = (((double) j) / HEIGHT) * (Y_MAX - Y_MIN) + Y_MIN;
            x = y = 0;
            iterations = 0;
            while (x * x + y * y < 4 && iterations < MAX_ITERATIONS) {
                x_tmp = x * x - y * y + x0;
                y = 2 * x * y + y0;
                x = x_tmp;
                iterations++;
            }
            if (iterations == MAX_ITERATIONS) {
                set_pixel(buffer, i, j, 0, 0, 0);
            } else {
                real = cos(iterations * log(sqrt(x * x + y * y))) / log(2);
                imag = sin(iterations * log(sqrt(x * x + y * y))) / log(2);
                set_pixel(buffer, i, j, (unsigned char) (255 * real),
                          (unsigned char) (255 * imag), (unsigned char) (255 * (real + imag) / 2));
            }
        }
    }
}

int main(int argc, char **argv) {
    unsigned char *buffer = (unsigned char *) malloc(WIDTH * HEIGHT * 3);
    draw_fractal(buffer);
    FILE *f = fopen("fractal.bmp", "wb");
    fprintf(f, "P6 %d %d 255\n", WIDTH, HEIGHT);
    fwrite(buffer, WIDTH * HEIGHT, 3, f);
    free(buffer);
    fclose(f);
    printf("Fractal saved to fractal.bmp\n");
    return 0;
}