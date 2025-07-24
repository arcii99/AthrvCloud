//FormAI DATASET v1.0 Category: Game of Life ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 50
#define COLS 100

int grid[ROWS][COLS];
int newgrid[ROWS][COLS];

void initialize_grid();
void print_grid();
int update_cell(int row, int col);
void update_grid();

int main() {
    initialize_grid();
    print_grid();

    while (1) {
        update_grid();
        print_grid();
        usleep(100000);
    }
    return 0;
}

void initialize_grid() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid() {
    int i, j;

    printf("\033[2J"); // clear screen
    printf("\033[%d;%dH", 0, 0); // move cursor to top-left corner

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] ? 'X' : ' ');
        }
        printf("\n");
    }
}

int update_cell(int row, int col) {
    int neighbors = 0;
    int i, j;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue; // cell does not count as its own neighbor
            }
            int n_row = (row + i + ROWS) % ROWS; // wrap around if edge of grid is reached
            int n_col = (col + j + COLS) % COLS;
            neighbors += grid[n_row][n_col];
        }
    }

    if (grid[row][col] == 1 && (neighbors == 2 || neighbors == 3)) {
        return 1; // live cell survives
    } else if (grid[row][col] == 0 && neighbors == 3) {
        return 1; // dead cell becomes live
    } else {
        return 0; // cell dies or remains dead
    }
}

void update_grid() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            newgrid[i][j] = update_cell(i, j);
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = newgrid[i][j];
        }
    }
}