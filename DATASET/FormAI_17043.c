//FormAI DATASET v1.0 Category: Game of Life ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];
int buffer[ROWS][COLS];

/*
 * Romeo and Juliet Game of Life
 * A tragic love story where Romeo and Juliet 
 * are represented by two cells in a grid world
 */

void init_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == ROWS / 2 && j == COLS / 4) {
                grid[i][j] = 1; // Romeo
            } else if (i == ROWS / 2 && j == 3 * COLS / 4) {
                grid[i][j] = 1; // Juliet
            } else {
                grid[i][j] = rand() % 2;
            }
            buffer[i][j] = 0;
        }
    }
}

void print_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                if (i == ROWS / 2 && j == COLS / 4) {
                    printf("R"); // Romeo
                } else if (i == ROWS / 2 && j == 3 * COLS / 4) {
                    printf("J"); // Juliet
                } else {
                    printf("#");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int neighbors(int r, int c) {
    int count = 0;
    int i, j;
    for (i = r - 1; i <= r + 1; i++) {
        for (j = c - 1; j <= c + 1; j++) {
            if (i == ROWS || i < 0 || j == COLS || j < 0) {
                continue;
            }
            if (i == r && j == c) {
                continue;
            }
            count += grid[i][j];
        }
    }
    return count;
}

void step() {
    int i, j, n;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            n = neighbors(i, j);
            if (grid[i][j] == 0) {
                if (n == 3) {
                    buffer[i][j] = 1;
                } else {
                    buffer[i][j] = 0;
                }
            } else {
                if (n < 2 || n > 3) {
                    buffer[i][j] = 0;
                } else {
                    buffer[i][j] = 1;
                }
            }
        }
    }
    memcpy(grid, buffer, sizeof(grid));
}

int main() {
    srand(time(NULL));
    init_grid();
    while (1) {
        print_grid();
        printf("\n");
        step();
        printf("Press enter to continue...\n");
        getchar();
    }
    return 0;
}