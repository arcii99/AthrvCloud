//FormAI DATASET v1.0 Category: Fractal Generation ; Style: visionary
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define WIDTH 80           // width of the screen
#define HEIGHT 40          // height of the screen
#define MAX_ITERATIONS 30  // maximum number of iterations for the fractal
#define SCALE 3.0          // scale of the fractal
#define CENTER_X -0.745    // x coordinate of center of fractal
#define CENTER_Y 0.125     // y coordinate of center of fractal

// initialize the screen
void init_screen(char screen[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }
}

// draw the screen
void draw_screen(char screen[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(screen[i][j]);
        }
        putchar('\n');
    }
}

// get the point in the complex plane corresponding to a screen coordinate
void get_point(int x, int y, double *re, double *im) {
    *re = (x * 2 * SCALE / WIDTH) - SCALE + CENTER_X;
    *im = (y * SCALE / HEIGHT) - (SCALE / 2) + CENTER_Y;
}

// compute the number of iterations required for a point to escape the fractal
int compute_iterations(double c_re, double c_im) {
    double z_re = 0.0, z_im = 0.0;
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        double z_re_new = z_re * z_re - z_im * z_im + c_re;
        double z_im_new = 2 * z_re * z_im + c_im;
        z_re = z_re_new;
        z_im = z_im_new;
        if (sqrt(z_re * z_re + z_im * z_im) > 2.0) {
            return i;
        }
    }
    return MAX_ITERATIONS;
}

// draw a character on the screen at the specified location
void draw_char(char screen[HEIGHT][WIDTH], int x, int y, char ch) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        screen[y][x] = ch;
    }
}

int main() {
    char screen[HEIGHT][WIDTH];
    init_screen(screen);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double c_re, c_im;
            get_point(x, y, &c_re, &c_im);
            int iterations = compute_iterations(c_re, c_im);
            char ch;
            if (iterations == MAX_ITERATIONS) {
                ch = '#';
            } else if (iterations > MAX_ITERATIONS / 2) {
                ch = '+';
            } else if (iterations > MAX_ITERATIONS / 3) {
                ch = '=';
            } else {
                ch = '-';
            }
            draw_char(screen, x, y, ch);
        }
    }
    draw_screen(screen);
    return 0;
}