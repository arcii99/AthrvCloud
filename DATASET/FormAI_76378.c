//FormAI DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void print_grid(int grid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int grid[][COLS], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && (i != row || j != col)) {
                count += grid[i][j];
            }
        }
    }
    return count;
}

void update_grid(int grid[][COLS]) {
    int temp[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    temp[i][j] = 0;
                } else {
                    temp[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    temp[i][j] = 1;
                } else {
                    temp[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    int grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    printf("Welcome to the Game of Life!\n");
    printf("Press ENTER to begin.\n");
    getchar();
    while (1) {
        print_grid(grid);
        printf("Press ENTER to continue or CTRL+C to exit.\n");
        getchar();
        system("clear");
        update_grid(grid);
    }
    return 0;
}