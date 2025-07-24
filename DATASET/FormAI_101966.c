//FormAI DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 50
#define ALIVE 'x'
#define DEAD ' '

char grid[ROWS][COLS];

void init_grid() {
    srand(time(NULL));
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (rand() % 2 == 0) {
                grid[row][col] = ALIVE;
            } else {
                grid[row][col] = DEAD;
            }
        }
    }
}

void print_grid() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c", grid[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int row, int col) {
    int count = 0;
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = col - 1; c <= col + 1; c++) {
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && !(r == row && c == col)) {
                if (grid[r][c] == ALIVE) {
                    count++;
                }
            }
        }
    }
    return count;
}

void update_grid() {
    char temp_grid[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int neighbors = count_neighbors(row, col);
            if (grid[row][col] == ALIVE) {
                if (neighbors < 2 || neighbors > 3) {
                    temp_grid[row][col] = DEAD;
                } else {
                    temp_grid[row][col] = ALIVE;
                }
            } else {
                if (neighbors == 3) {
                    temp_grid[row][col] = ALIVE;
                } else {
                    temp_grid[row][col] = DEAD;
                }
            }
        }
    }
    // copy temp grid back to original
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = temp_grid[row][col];
        }
    }
}

int main() {
    init_grid();
    printf("Welcome to Happy Game of Life!\n");
    printf("Initial configuration:\n");
    print_grid();
    for (int i = 1; i <= 10; i++) {
        printf("Generation %d:\n", i);
        update_grid();
        print_grid();
    }
    printf("Thanks for playing Happy Game of Life!\n");
    return 0;
}