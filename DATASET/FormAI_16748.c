//FormAI DATASET v1.0 Category: Fractal Generation ; Style: sophisticated
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

#define MAX_ITERATIONS 1000
#define ITERATIONS_MULTIPLIER 4
#define COLOR_THETA 15

#define X_MIN -2.0
#define Y_MIN -2.0
#define X_MAX 2.0
#define Y_MAX 2.0

typedef struct complex {
    double real;
    double imag;
} complex;

int get_color(int iterations) {
    double theta = (double)iterations / COLOR_THETA;
    int blue = (int)((1.0 - cos(theta)) / 2.0 * 255.0);
    int red = (int)((1.0 - cos(theta + 2.0 * M_PI / 3.0)) / 2.0 * 255.0);
    int green = (int)((1.0 - cos(theta + 4.0 * M_PI / 3.0)) / 2.0 * 255.0);
    return (red << 16) | (green << 8) | blue;
}

void calculate_mandelbrot(unsigned char* image_buffer, double zoom_factor, complex offset) {
    for (int x = 0; x < WINDOW_WIDTH; x++) {
        for (int y = 0; y < WINDOW_HEIGHT; y++) {
            complex c = {
                x * ((X_MAX - X_MIN) / (double)WINDOW_WIDTH) * zoom_factor + offset.real - (X_MAX - X_MIN) / 2.0,
                y * ((Y_MAX - Y_MIN) / (double)WINDOW_HEIGHT) * zoom_factor + offset.imag - (Y_MAX - Y_MIN) / 2.0
            };

            complex z = {0.0, 0.0};
            int iterations = 0;

            while (z.real * z.real + z.imag * z.imag <= 4.0 && iterations < MAX_ITERATIONS) {
                complex temp = {
                    z.real * z.real - z.imag * z.imag + c.real,
                    2.0 * z.real * z.imag + c.imag
                };
                z = temp;
                iterations++;
            }

            int color = get_color(iterations);
            int index = (y * WINDOW_WIDTH + x) * 3;
            image_buffer[index] = (color & 0xFF0000) >> 16;
            image_buffer[index + 1] = (color & 0x00FF00) >> 8;
            image_buffer[index + 2] = color & 0x0000FF;
        }
    }
}

int main(int argc, char** argv) {
    unsigned char* image_buffer = (unsigned char*)malloc(WINDOW_WIDTH * WINDOW_HEIGHT * 3);
    complex center = {0.0, 0.0};
    double zoom_factor = 1.0;

    if (image_buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory for image buffer\n");
        return EXIT_FAILURE;
    }

    bool running = true;
    while (running) {
        calculate_mandelbrot(image_buffer, zoom_factor, center);

        // Write image_buffer to file or display on screen

        int key = getchar();
        if (key == '+') {
            zoom_factor *= ITERATIONS_MULTIPLIER;
        } else if (key == '-') {
            zoom_factor /= ITERATIONS_MULTIPLIER;
        } else if (key == 'w') {
            center.imag += (Y_MAX - Y_MIN) / 4.0 * zoom_factor / WINDOW_HEIGHT;
        } else if (key == 'a') {
            center.real -= (X_MAX - X_MIN) / 4.0 * zoom_factor / WINDOW_WIDTH;
        } else if (key == 's') {
            center.imag -= (Y_MAX - Y_MIN) / 4.0 * zoom_factor / WINDOW_HEIGHT;
        } else if (key == 'd') {
            center.real += (X_MAX - X_MIN) / 4.0 * zoom_factor / WINDOW_WIDTH;
        } else if (key == 'q') {
            running = false;
        }
    }

    free(image_buffer);
    return EXIT_SUCCESS;
}