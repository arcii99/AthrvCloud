//FormAI DATASET v1.0 Category: Fractal Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 128
#define HEIGHT 64

int grid[HEIGHT][WIDTH] = { 0 };

void fill(int x, int y, int size, int value) {
    if (size == 1) {
        grid[y][x] = value;
        return;
    }

    int half_size = size / 2;
    int new_value = rand() % 2 ? value : -value;

    fill(x - half_size, y - half_size, half_size, new_value);
    fill(x + half_size, y - half_size, half_size, new_value);
    fill(x - half_size, y + half_size, half_size, new_value);
    fill(x + half_size, y + half_size, half_size, new_value);
}

int main() {
    srand(time(NULL));

    int size = HEIGHT / 2;
    int value = 1;

    fill(WIDTH / 2, HEIGHT / 2, size, value);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(grid[y][x] ? '#' : '.');
        }
        putchar('\n');
    }

    return 0;
}