//FormAI DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 40

void print_grid(char grid[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
       for (int j = 0; j < COLUMNS; j++) {
           putchar(grid[i][j]);
       }
       puts("");
    }
}

int count_neighbors(char grid[ROWS][COLUMNS], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) {
                continue;
            }
            if (i < 0 || i >= ROWS || j < 0 || j >= COLUMNS) {
                continue;
            }
            if (grid[i][j] == 'X') {
                count++;
            }
        }
    }
    return count;
}

void update_grid(char grid[ROWS][COLUMNS]) {
    char next_grid[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j] == 'X' && neighbors < 2) {
                next_grid[i][j] = ' ';
            }
            else if (grid[i][j] == 'X' && (neighbors == 2 || neighbors == 3)) {
                next_grid[i][j] = 'X';
            }
            else if (grid[i][j] == 'X' && neighbors > 3) {
                next_grid[i][j] = ' ';
            }
            else if (grid[i][j] == ' ' && neighbors == 3) {
                next_grid[i][j] = 'X';
            }
            else {
                next_grid[i][j] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

void initialize_grid(char grid[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = ' ';
        }
    }
    srand(time(NULL));
    for (int i = 0; i < 200; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLUMNS;
        grid[row][col] = 'X';
    } 
}

int main() {
    char grid[ROWS][COLUMNS];
    initialize_grid(grid);
    print_grid(grid);
    while (1) {
        update_grid(grid);
        print_grid(grid);
        getchar(); // wait for user to press enter
    }
    return 0;
}