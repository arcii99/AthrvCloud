//FormAI DATASET v1.0 Category: Fractal Generation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 160
#define HEIGHT 40
#define MAX_ITERATIONS 50

void clear_screen() {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void print_image(char image[HEIGHT][WIDTH]) {
    clear_screen();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(image[i][j]);
        }
        putchar('\n');
    }
}

bool contains(int set[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (set[i] == num) {
            return true;
        }
    }
    return false;
}

double remap(double val, double start1, double stop1, double start2, double stop2) {
    return start2 + (stop2 - start2) * ((val - start1) / (stop1 - start1));
}

int main() {
    int escape_val = MAX_ITERATIONS;
    char ascii_set[] = "%%%%%%%#@@@@@@@**********-----------++|||";
    int ascii_set_size = sizeof(ascii_set) / sizeof(char);
    int points[] = {-1, 1};
    int num_points = sizeof(points) / sizeof(int);
    char image[HEIGHT][WIDTH] = {{' '}};
    double cx, cy, zx, zy, zx_new, zy_new, radius, phi, x, y;
    int iterations, index;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            index = 0;
            iterations = 0;
            cx = remap(j, 0, WIDTH, -2.25, 0.75);
            cy = remap(i, 0, HEIGHT, -1.5, 1.5);
            zx = 0;
            zy = 0;
            radius = 0;
            while (iterations < MAX_ITERATIONS && radius <= 4) {
                zx_new = zx * zx - zy * zy + cx;
                zy_new = 2 * zx * zy + cy;
                zx = zx_new;
                zy = zy_new;
                radius = zx * zx + zy * zy;
                iterations++;
            }
            phi = atan2(zy, zx);
            index = (int) round(remap(iterations, 0, MAX_ITERATIONS, 1, ascii_set_size));
            x = remap(cos(phi), -1, 1, 0, num_points - 1);
            y = remap(sin(phi), -1, 1, 0, num_points - 1);
            if (contains(points, num_points, (int) round(x)) && contains(points, num_points, (int) round(y))) {
                image[i][j] = ' ';
            } else {
                image[i][j] = ascii_set[index - 1];
            }
        }
    }
    print_image(image);
    return 0;
}