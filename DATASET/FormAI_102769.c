//FormAI DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 50

void clear_screen() {
    printf("\033[2J\033[%d;%dH", 0, 0);
}

void display(char grid[][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            putchar(grid[i][j]);
        }
        putchar('\n');
    }
}

int alive_neighbors(char grid[][COLUMNS], int r, int c) {
    int count = 0;
    for (int i = r - 1; i <= r + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if (i == r && j == c) {
                continue;
            }
            int row = i;
            int col = j;
            if (row < 0) {
                row = ROWS - 1;
            } else if (row >= ROWS) {
                row = 0;
            }
            if (col < 0) {
                col = COLUMNS - 1;
            } else if (col >= COLUMNS) {
                col = 0;
            }
            if (grid[row][col] == '#') {
                count++;
            }   
        }
    }
    return count;
}

void update(char grid[][COLUMNS]) {
    char new_grid[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int neighbors = alive_neighbors(grid, i, j);
            if (grid[i][j] == '#') {
                if (neighbors == 2 || neighbors == 3) {
                    new_grid[i][j] = '#';
                } else {
                    new_grid[i][j] = ' ';
                }
            } else {
                if (neighbors == 3) {
                    new_grid[i][j] = '#';
                } else {
                    new_grid[i][j] = ' ';
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

void randomize(char grid[][COLUMNS], float density) {
    int count = (int)(ROWS * COLUMNS * density);
    for (int i = 0; i < count; i++) {
        int r = rand() % ROWS;
        int c = rand() % COLUMNS;
        grid[r][c] = '#';
    }
}

int main() {
    srand(time(NULL));
    char grid[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = ' ';
        }
    }
    randomize(grid, 0.3);
    while (1) {
        clear_screen();
        display(grid);
        update(grid);
        usleep(100000);
    }
    return 0;
}