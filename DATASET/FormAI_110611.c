//FormAI DATASET v1.0 Category: Fractal Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 50
#define MAX_DEPTH 10
#define MAX_ITER 100000

typedef struct {
    double x, y;
} Vec2;

typedef struct {
    int x, y;
} Coord;

int mandelbrot_escape_time(double x0, double y0) {
    double x = 0, y = 0, mag = 0;
    int n;
    for (n = 0; n < MAX_ITER && mag < 4.0; ++n) {
        double xnew = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xnew;
        mag = x*x + y*y;
    }
    return n;
}

void render_mandelbrot(int mandelbrot[WIDTH][HEIGHT]) {
    int x, y;
    for (y = 0; y < HEIGHT; ++y)
        for (x = 0; x < WIDTH; ++x) {
            double nx = (x - WIDTH/2.0) / (WIDTH/4.0);
            double ny = (y - HEIGHT/2.0) / (WIDTH/4.0);
            mandelbrot[x][y] = mandelbrot_escape_time(nx, ny);
        }
}

void render_fractal(double a, double b) {
    int mandelbrot[WIDTH][HEIGHT];
    int i, j;
    char ascii[WIDTH * (HEIGHT+1) + 1];
    render_mandelbrot(mandelbrot);
    for (j = HEIGHT-1; j >= 0; --j) {
        int k = 0;
        for (i = 0; i < WIDTH; ++i) {
            int iter = mandelbrot[i][j];
            char c = iter == MAX_ITER ? ' ' : '0' + (iter % 10);
            ascii[k++] = c;
        }
        ascii[k++] = '\n';
        ascii[k] = '\0';
        printf("%s", ascii);
    }
}

void draw_fractal(int depth, double a1, double b1, double a2, double b2) {
    double a = (a1 + a2) / 2, b = (b1 + b2) / 2;
    if (depth >= MAX_DEPTH) {
        render_fractal(a, b);
    } else {
        draw_fractal(depth+1, a1, b1, a, b2);
        draw_fractal(depth+1, a, b1, a2, b2);
    }
}

int main() {
    draw_fractal(0, -2.0, -1.0, 2.0, 1.0);
    return 0;
}