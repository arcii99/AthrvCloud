//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 64
#define MAX_DEPTH 4

void draw_fractal(char array[SIZE][SIZE], int x, int y, int size, int depth) {
    if (depth == MAX_DEPTH) {
        array[x][y] = '*';
        return;
    }

    int half_size = size / 2;
    draw_fractal(array, x - half_size, y - half_size, half_size, depth + 1);
    draw_fractal(array, x + half_size, y - half_size, half_size, depth + 1);
    draw_fractal(array, x - half_size, y + half_size, half_size, depth + 1);
    draw_fractal(array, x + half_size, y + half_size, half_size, depth + 1);
}

int main() {
    char array[SIZE][SIZE] = {0};
    draw_fractal(array, SIZE / 2, SIZE / 2, SIZE, 0);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", array[j][i] == '*' ? '*' : ' ');
        }
        printf("\n");
    }

    return 0;
}