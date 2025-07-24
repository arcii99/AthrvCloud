//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 100

typedef struct {
    double real;
    double imag;
} complex;

void set_pixel(char (*screen)[WIDTH], int x, int y, char color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        screen[y][x] = color;
    }
}

void clear_screen(char (*screen)[WIDTH], char color) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = color;
        }
    }
}

int iterate(complex c) {
    complex z = {0, 0};
    int i;
    for (i = 0; i < MAX_ITER && z.real*z.real + z.imag*z.imag < 4; i++) {
        complex z_tmp = z;
        z.real = z_tmp.real*z_tmp.real - z_tmp.imag*z_tmp.imag + c.real;
        z.imag = 2*z_tmp.real*z_tmp.imag + c.imag;
    }
    return i;
}

void draw_fractal(char (*screen)[WIDTH], int (*palette)[MAX_ITER], complex center, double scale) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            complex c = {(j - WIDTH/2)*(4.0*scale/WIDTH) + center.real,
                         (i - HEIGHT/2)*(4.0*scale/HEIGHT) + center.imag};
            int iteration = iterate(c);
            set_pixel(screen, j, i, palette[i][iteration]);
        }
    }
}

int main() {
    char screen[HEIGHT][WIDTH];
    int palette[HEIGHT][MAX_ITER];
    clear_screen(screen, ' ');
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < MAX_ITER; j++) {
            palette[i][j] = 30+i/10;
        }
    }
    complex center = {0.5, 0.0};
    double scale = 1.0;
    draw_fractal(screen, palette, center, scale);
    return 0;
}