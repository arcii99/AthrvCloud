//FormAI DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 60

int grid[ROWS][COLS];

void init_grid()
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid()
{
    printf("\033[H\033[J");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("O ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int row, int col)
{
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                count += grid[i][j];
            }
        }
    }
    return count;
}

void update_grid()
{
    int new_grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int count = count_neighbors(i, j);
            if (grid[i][j] == 1 && (count == 2 || count == 3)) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] == 0 && count == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main()
{
    init_grid();
    while (1) {
        print_grid();
        update_grid();
        // add some delay here to slow down the updates
    }
    return 0;
}