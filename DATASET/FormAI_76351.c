//FormAI DATASET v1.0 Category: Fractal Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define HEIGHT 60
#define WIDTH 120
#define MAX_ITERATIONS 100

void reset(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

bool is_in_set(double x, double y) {
    double zx = 0.0;
    double zy = 0.0;
    for (int i = 1; i <= MAX_ITERATIONS; i++) {
        double new_zx = zx * zx - zy * zy + x;
        double new_zy = 2 * zx * zy + y;
        zx = new_zx;
        zy = new_zy;
        if (zx * zx + zy * zy > 4.0) {
            return false;
        }
    }
    return true;
}

void generate_fractal(char board[HEIGHT][WIDTH], double x_min, double x_max, double y_min, double y_max) {
    double x_step = (x_max - x_min) / WIDTH;
    double y_step = (y_max - y_min) / HEIGHT;
    double x = x_min;
    double y = y_max;
    for (int i = 0; i < HEIGHT; i++) {
        x = x_min;
        for (int j = 0; j < WIDTH; j++) {
            if (is_in_set(x, y)) {
                board[i][j] = '*';
            }
            x += x_step;
        }
        y -= y_step;
    }
}

int main() {
    char board[HEIGHT][WIDTH];
    reset(board);
    generate_fractal(board, -2.0, 2.0, -1.0, 1.0);
    print_board(board);
    return 0;
}