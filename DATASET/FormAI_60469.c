//FormAI DATASET v1.0 Category: Fractal Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_DEPTH 1000
#define MAX_ITERATIONS 10000

typedef struct {
    double x;
    double y;
} complex;

bool available_color[256];

void initialize_available_color() {
    for (int i=0; i<256; i++) {
        available_color[i] = true;
    }
}

int get_random_color() {
    int color_index = rand() % 256;
    while (!available_color[color_index]) {
        color_index = rand() % 256;
    }
    available_color[color_index] = false;
    return color_index;
}

void reset_available_color(int color_index) {
    available_color[color_index] = true;
}

int get_mandelbrot_iterations(complex c) {
    complex z = {0, 0};
    int iterations = 0;
    while (iterations < MAX_ITERATIONS && z.x*z.x + z.y*z.y < 4) {
        complex z_new = {z.x*z.x - z.y*z.y + c.x, 2*z.x*z.y + c.y};
        z = z_new;
        iterations++;
    }
    return iterations;
}

void generate_fractal(FILE* fp) {
    srand(time(NULL));
    initialize_available_color();
    complex center = {-0.75, 0};
    double scale = 1;
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            int color_index;
            double x = center.x - (WIDTH/2 - j) * scale / WIDTH;
            double y = center.y + (HEIGHT/2 - i) * scale / HEIGHT;
            complex c = {x, y};
            int iterations = get_mandelbrot_iterations(c);
            if (iterations == MAX_ITERATIONS) {
                color_index = 0;
            } else {
                color_index = get_random_color();
            }
            fprintf(fp, "%d %d %d ", color_index, color_index, color_index);
            if (j == WIDTH-1) {
                fprintf(fp, "\n");
            }
            if ((i * WIDTH + j) % 10000 == 0) {
                printf("Progress: %d/%d\n", i * WIDTH + j, WIDTH * HEIGHT);
            }
        }
    }
}

int main() {
    FILE* fp = fopen("fractal.ppm", "w+");
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    generate_fractal(fp);
    fclose(fp);
    return 0;
}