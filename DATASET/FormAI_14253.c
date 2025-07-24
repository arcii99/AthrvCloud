//FormAI DATASET v1.0 Category: Fractal Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_ITER 1000

int mandelbrot(double x, double y) {
    double a = 0.0, b = 0.0, temp;
    int n;
    for (n = 0; n < MAX_ITER; n++) {
        if (a*a + b*b > 4.0) {
            return n;
        }
        temp = a*a - b*b + x;
        b = 2.0*a*b + y;
        a = temp;
    }
    return MAX_ITER;
}

void draw_mandelbrot() {
    int x, y, iter;
    double scale_x = 3.0 / WIDTH;
    double scale_y = 2.0 / HEIGHT;
    double offset_x = -2.0;
    double offset_y = -1.0;
    printf("P2\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_ITER);
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            double real = x * scale_x + offset_x;
            double imag = y * scale_y + offset_y;
            iter = mandelbrot(real, imag);
            printf("%d ", iter);
        }
        printf("\n");
    }
}

int main() {
    draw_mandelbrot();
    return 0;
}