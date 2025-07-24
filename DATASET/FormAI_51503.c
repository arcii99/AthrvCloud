//FormAI DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void display(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(char grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        if (i < 0 || i >= ROWS) {
            continue;
        }
        for (int j = col - 1; j <= col + 1; j++) {
            if (j < 0 || j >= COLS) {
                continue;
            }
            if (i == row && j == col) {
                continue;
            }
            if (grid[i][j] == 'X') {
                count++;
            }
        }
    }
    return count;
}

void iterate(char grid[ROWS][COLS]) {
    char new_grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j] == 'X') {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = ' ';
                } else {
                    new_grid[i][j] = 'X';
                }
            } else {
                if (neighbors == 3) {
                    new_grid[i][j] = 'X';
                } else {
                    new_grid[i][j] = ' ';
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    char grid[ROWS][COLS] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'X', ' ', 'X', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    int generations = 0;
    printf("Welcome to Ada Lovelace's Game of Life!\n");
    printf("Press Enter to begin.");
    getchar();

    while (1) {
        printf("Generation: %d\n", generations);
        printf("Press Enter to iterate.");
        getchar();
        system("clear"); // Change this to "cls" for Windows
        display(grid);
        iterate(grid);
        generations++;
    }
    return 0;
}