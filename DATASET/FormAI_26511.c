//FormAI DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 30
#define COLUMNS 60

int current_grid[ROWS][COLUMNS];
int next_grid[ROWS][COLUMNS];

void initialize_grid() {
    // initialize the grid with random values
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            current_grid[row][column] = rand() % 2;
        }
    }
}

void display_grid() {
    // display the grid
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            if (current_grid[row][column] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int row, int column) {
    // count the number of live neighbors around a cell
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighbor_row = row + i;
            int neighbor_column = column + j;
            if (neighbor_row >= ROWS) {
                neighbor_row = 0;
            } else if (neighbor_row < 0) {
                neighbor_row = ROWS - 1;
            }
            if (neighbor_column >= COLUMNS) {
                neighbor_column = 0;
            } else if (neighbor_column < 0) {
                neighbor_column = COLUMNS - 1;
            }
            count += current_grid[neighbor_row][neighbor_column];
        }
    }
    count -= current_grid[row][column];
    return count;
}

void play_game_of_life() {
    // play the game of life
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            int neighbors = count_neighbors(row, column);
            if (current_grid[row][column] == 1 && neighbors < 2) {
                next_grid[row][column] = 0;
            } else if (current_grid[row][column] == 1 && (neighbors == 2 || neighbors == 3)) {
                next_grid[row][column] = 1;
            } else if (current_grid[row][column] == 1 && neighbors > 3) {
                next_grid[row][column] = 0;
            } else if (current_grid[row][column] == 0 && neighbors == 3) {
                next_grid[row][column] = 1;
            }
        }
    }
    // update the grid
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            current_grid[row][column] = next_grid[row][column];
        }
    }
}

int main() {
    initialize_grid();
    while (1) {
        display_grid();
        usleep(100000);
        play_game_of_life();
    }
    return 0;
}