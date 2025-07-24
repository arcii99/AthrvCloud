//FormAI DATASET v1.0 Category: Game of Life ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void print_grid(int grid[][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(int grid[][COLS], int row, int col) {
    int count = 0;

    if (row > 0 && grid[row - 1][col]) count++;
    if (row < ROWS - 1 && grid[row + 1][col]) count++;
    if (col > 0 && grid[row][col - 1]) count++;
    if (col < COLS - 1 && grid[row][col + 1]) count++;
    if (row > 0 && col > 0 && grid[row - 1][col - 1]) count++;
    if (row > 0 && col < COLS - 1 && grid[row - 1][col + 1]) count++;
    if (row < ROWS - 1 && col > 0 && grid[row + 1][col - 1]) count++;
    if (row < ROWS - 1 && col < COLS - 1 && grid[row + 1][col + 1]) count++;

    return count;
}

void apply_rules(int grid[][COLS], int new_grid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                }
                else {
                    new_grid[i][j] = 1;
                }
            }
            else {
                if (neighbors == 3) {
                    new_grid[i][j] = 1;
                }
                else {
                    new_grid[i][j] = 0;
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
    int grid[ROWS][COLS] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    int new_grid[ROWS][COLS];

    print_grid(grid);

    while (1) {
        apply_rules(grid, new_grid);
        print_grid(grid);
        system("cls");
    }

    return 0;
}