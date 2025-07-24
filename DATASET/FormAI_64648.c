//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 200
#define HEIGHT 100

void draw_pixel(char grid[][WIDTH], int x, int y, char pixel) {
    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) {
        return;
    }
    grid[y][x] = pixel;
}

void generate_pattern(char grid[][WIDTH]) {
    srand(time(NULL));
    int x, y;
    char pixel;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            pixel = (rand() % 2 == 0) ? 'X' : 'O';
            draw_pixel(grid, x, y, pixel);
        }
    }
}

void print_grid(char grid[][WIDTH]) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c ", grid[y][x]);
        }
        printf("\n");
    }
}

int main(void) {
    char grid[HEIGHT][WIDTH];
    generate_pattern(grid);
    print_grid(grid);

    return 0;
}