//FormAI DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int grid[ROWS][COLS];

// Function to print the grid
void print_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] ? '*' : '-');
        }
        printf("\n");
    }
}

// Function to check the status of a cell
int get_state(int row, int col) {
    int count = 0;
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            if ((i < 0 || j < 0 || i >= ROWS || j >= COLS) || (i == row && j == col)) {
                continue;
            }
            if (grid[i][j]) {
                count++;
            }
        }
    }
    if (grid[row][col]) {
        if (count < 2 || count > 3) {
            return 0;
        } else {
            return 1;
        }
    } else {
        if (count == 3) {
            return 1;
        } else {
            return 0;
        }
    }
}

// Function to update the grid
void update_grid() {
    int new_grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            new_grid[i][j] = get_state(i, j);
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    printf("Welcome to the Game of Life!\n");
    printf("Generating random initial configuration...\n");
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    printf("Initial configuration:\n");
    print_grid();
    printf("\nPress enter to start the simulation.\n");
    getchar();
    while (1) {
        update_grid();
        printf("\033[2J"); // clear console
        printf("\033[%d;%dH", 0, 0); // move cursor to top left
        printf("Current configuration:\n");
        print_grid();
        printf("\nPress enter to continue or Ctrl+C to exit.\n");
        getchar();
    }
    return 0;
}