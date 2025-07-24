//FormAI DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define GEN_COUNT 50

void display(char grid[HEIGHT][WIDTH]) {
    printf("\033[H"); // move cursor to the top left corner
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void generate(char grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int num = rand() % 2;
            grid[i][j] = num == 1 ? '#' : ' ';
        }
    }
}

int count_neighbors(char grid[HEIGHT][WIDTH], int i, int j) {
    int count = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0)
                continue;
            if (grid[(i + x + HEIGHT) % HEIGHT][(j + y + WIDTH) % WIDTH] == '#')
                count++;
        }
    }
    return count;
}

void update(char grid[HEIGHT][WIDTH]) {
    char new_grid[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int count = count_neighbors(grid, i, j);
            if (grid[i][j] == '#') {
                if (count < 2 || count > 3)
                    new_grid[i][j] = ' ';
                else
                    new_grid[i][j] = '#';
            } else {
                if (count == 3)
                    new_grid[i][j] = '#';
                else
                    new_grid[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    char grid[HEIGHT][WIDTH];
    generate(grid);
    for (int i = 0; i < GEN_COUNT; i++) {
        display(grid);
        update(grid);
        usleep(200000);
    }
    return 0;
}