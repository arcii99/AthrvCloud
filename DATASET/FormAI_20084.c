//FormAI DATASET v1.0 Category: Game of Life ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define ALIVE 'X'
#define DEAD ' '

void print_grid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("|\n");
    }
}

void generate_initial_grid(char grid[ROWS][COLS]) {
    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int r = rand() % 2;
            if (r == 0) {
                grid[i][j] = DEAD;
            } else {
                grid[i][j] = ALIVE;
            }
        }
    }
}

int count_neighbors(char grid[ROWS][COLS], int r, int c) {
    int count = 0;
    for (int i = r - 1; i <= r + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if (i < 0 || i >= ROWS || j < 0 || j >= COLS) {
                continue;
            }
            if (i == r && j == c) {
                continue;
            }
            if (grid[i][j] == ALIVE) {
                count++;
            }
        }
    }
    return count;
}

void update_grid(char grid[ROWS][COLS], char newgrid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int count = count_neighbors(grid, i, j);
            if (grid[i][j] == ALIVE) {
                if (count < 2) {
                    newgrid[i][j] = DEAD;
                } else if (count == 2 || count == 3) {
                    newgrid[i][j] = ALIVE;
                } else if (count > 3) {
                    newgrid[i][j] = DEAD;
                }
            } else {
                if (count == 3) {
                    newgrid[i][j] = ALIVE;
                } else {
                    newgrid[i][j] = DEAD;
                }
            }
        }
    }
}

int main() {
    char grid[ROWS][COLS];
    char newgrid[ROWS][COLS];

    generate_initial_grid(grid);
    while (1) {
        system("cls");
        print_grid(grid);
        update_grid(grid, newgrid);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = newgrid[i][j];
            }
        }
    }

    return 0;
}