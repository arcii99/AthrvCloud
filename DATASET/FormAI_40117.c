//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000

typedef struct {
    int r, g, b;
} color_t;

void put_pixel(unsigned char* buffer, int x, int y, color_t color) {
    int index = (x + y * WIDTH) * 3;
    buffer[index] = color.r;
    buffer[index + 1] = color.g;
    buffer[index + 2] = color.b;
}

color_t compute_color(int iterations) {
    if (iterations == MAX_ITERATIONS) {
        return (color_t){0, 0, 0};
    }
    double t = (double)iterations / MAX_ITERATIONS;
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (color_t){r, g, b};
}

void compute_mandelbrot_set(unsigned char* buffer) {
    double x_min = -2.0;
    double x_max = 1.0;
    double y_min = -1.5;
    double y_max = 1.5;
    double dx = (x_max - x_min) / WIDTH;
    double dy = (y_max - y_min) / HEIGHT;
    int i, j, n, iterations;
    double x, y, x0, y0, x_tmp;
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            x0 = x_min + i * dx;
            y0 = y_min + j * dy;
            x = 0.0;
            y = 0.0;
            iterations = 0;
            while (x * x + y * y < 4 && iterations < MAX_ITERATIONS) {
                x_tmp = x * x - y * y + x0;
                y = 2 * x * y + y0;
                x = x_tmp;
                iterations++;
            }
            put_pixel(buffer, i, j, compute_color(iterations));
        }
    }
}

int main(int argc, char** argv) {
    unsigned char* buffer = malloc(WIDTH * HEIGHT * 3);
    if (buffer == NULL) {
        fprintf(stderr, "Error: could not allocate buffer\n");
        return 1;
    }
    compute_mandelbrot_set(buffer);
    FILE* file = fopen("mandelbrot.ppm", "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file for writing\n");
        return 1;
    }
    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(buffer, sizeof(unsigned char), WIDTH * HEIGHT * 3, file);
    fclose(file);
    free(buffer);
    return 0;
}