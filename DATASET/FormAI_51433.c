//FormAI DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITERATIONS 500
#define SMOOTHING_RADIUS 0.1

typedef struct {
    double x;
    double y;
} vector2;

int mandelbrot(double cx, double cy) {
    double zx = 0;
    double zy = 0;
    int iterations = 0;

    while (zx * zx + zy * zy < 4.0 && iterations < MAX_ITERATIONS) {
        double new_zx = zx * zx - zy * zy + cx;
        double new_zy = 2 * zx * zy + cy;
        zx = new_zx;
        zy = new_zy;
        iterations++;
    }

    if (iterations >= MAX_ITERATIONS) {
        return 0;
    }

    double smoothed_iterations = iterations + 1 - log2(log2(zx * zx + zy * zy));
    double color = (double) smoothed_iterations / MAX_ITERATIONS;

    if (color > 1.0) {
        color = 1.0;
    }

    return (int) (color * 255 + 0.5);
}

vector2 rotate(vector2 v, double angle) {
    vector2 result;
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    result.x = v.x * cos_a + v.y * sin_a;
    result.y = v.y * cos_a - v.x * sin_a;
    return result;
}

int main() {
    int i, j;

    srand(time(NULL));

    vector2 vertices[3] = {
            {0.0, -1.0},
            {sqrt(3.0) / 2.0, 0.5},
            {-sqrt(3.0) / 2.0, 0.5}
    };

    int colors[WIDTH][HEIGHT];

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            colors[i][j] = 0;
        }
    }

    double cx = 0.0;
    double cy = 0.4;

    for (i = 0; i < 10000; i++) {
        int vertex = rand() % 3;
        vector2 point = vertices[vertex];
        cx = (cx + point.x) / 2.0;
        cy = (cy + point.y) / 2.0;
        double angle = ((double) rand() / RAND_MAX) * M_PI;

        vector2 direction = {cx, cy};
        direction = rotate(direction, angle);

        int x = (int) ((direction.x + 1.0) * WIDTH / 2.0);
        int y = (int) ((direction.y + 1.0) * HEIGHT / 2.0);

        colors[x][y] += mandelbrot(cx, cy);
    }

    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            int color = colors[i][j] / 4;

            if (color > 255) {
                color = 255;
            }

            if (color > 0) {
                putchar('#');
            } else {
                putchar(' ');
            }
        }

        putchar('\n');
    }

    return 0;
}