//FormAI DATASET v1.0 Category: Fractal Generation ; Style: recursive
#include <stdio.h>

#define WIDTH 120
#define HEIGHT 40

void draw_fractal(char mat[][WIDTH], int x, int y, int size) {
    if (size == 1) {
        mat[y][x] = '#';
        return;
    }
    int half_size = size / 2;
    draw_fractal(mat, x, y, half_size);
    draw_fractal(mat, x + half_size, y, half_size);
    draw_fractal(mat, x, y + half_size, half_size);
    draw_fractal(mat, x + half_size, y + half_size, half_size);
}

int main() {
    char matrix[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = ' ';
        }
    }
    draw_fractal(matrix, 0, 0, HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}