//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 20
#define HEIGHT 20
#define PIXEL_SIZE 5

bool grid[WIDTH][HEIGHT];

void seed_grid() {
    srand((unsigned int) time(NULL));
    for(int row = 0; row < HEIGHT; row++) {
        for(int column = 0; column < WIDTH; column++) {
            grid[row][column] = rand() < RAND_MAX / 2;
        }
    }
}

void update_grid() {
    bool new_grid[WIDTH][HEIGHT];
    for(int row = 0; row < HEIGHT; row++) {
        for(int column = 0; column < WIDTH; column++) {
            int neighbours = 0;
            for(int x = -1; x <= 1; x++) {
                for(int y = -1; y <= 1; y++) {
                    if(x == 0 && y == 0) {
                        continue;
                    }
                    int r = row + x;
                    int c = column + y;
                    if(r < 0) {
                        r = HEIGHT - 1;
                    }
                    if(c < 0) {
                        c = WIDTH - 1;
                    }
                    if(r >= HEIGHT) {
                        r = 0;
                    }
                    if(c >= WIDTH) {
                        c = 0;
                    }
                    if(grid[r][c]) {
                        neighbours++;
                    }
                }
            }
            if(grid[row][column]) {
                new_grid[row][column] = neighbours == 2 || neighbours == 3;
            } else {
                new_grid[row][column] = neighbours == 3;
            }
        }
    }
    for(int row = 0; row < HEIGHT; row++) {
        for(int column = 0; column < WIDTH; column++) {
            grid[row][column] = new_grid[row][column];
        }
    }
}

void draw_grid() {
    for(int row = 0; row < HEIGHT; row++) {
        for(int column = 0; column < WIDTH; column++) {
            if(grid[row][column]) {
                printf("\033[48;5;22m");
            } else {
                printf("\033[48;5;16m");
            }
            printf(" ");
            for(int i = 1; i < PIXEL_SIZE; i++) {
                printf(" ");
            }
        }
        printf("\033[0m\n");
    }
}

int main() {
    seed_grid();
    while(true) {
        // Clear the console window.
        printf("\033[2J");
        // Set the cursor position to the top left corner of the window.
        printf("\033[1;1H");
        draw_grid();
        update_grid();
    }
    return 0;
}