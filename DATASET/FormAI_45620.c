//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define BLOCKED 0
#define OPEN 1

// initialize the grid with all blocked cells
void initialize_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = BLOCKED;
        }
    }
}

// print the grid to the console
void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// check if the given indices are within the grid boundaries
bool is_within_bounds(int x, int y) {
    return x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE;
}

// check if the cell is open (i.e., connected to the top row)
bool is_open(int grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    return is_within_bounds(x, y) && grid[x][y] == OPEN;
}

// recursive function to check if the current cell is connected to the top row
void check_openness(int grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    if (!is_within_bounds(x, y) || grid[x][y] == BLOCKED) {
        return;
    }
    grid[x][y] = OPEN;
    if (!is_open(grid, x - 1, y) &&
        !is_open(grid, x + 1, y) &&
        !is_open(grid, x, y - 1) &&
        !is_open(grid, x, y + 1)) {
        return;
    }
    check_openness(grid, x - 1, y);
    check_openness(grid, x + 1, y);
    check_openness(grid, x, y - 1);
    check_openness(grid, x, y + 1);
}

// simulate the percolation process
void simulate_percolation(int grid[GRID_SIZE][GRID_SIZE]) {
    srand(time(NULL));
    int random_x, random_y;
    while (true) {
        random_x = rand() % GRID_SIZE;
        random_y = rand() % GRID_SIZE;
        if (grid[random_x][random_y] == BLOCKED) {
            grid[random_x][random_y] = OPEN;
            check_openness(grid, random_x, random_y);
        }
        if (is_open(grid, 0, 0) && is_open(grid, GRID_SIZE - 1, GRID_SIZE - 1)) {
            return;
        }
    }
}

// main function
int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    initialize_grid(grid);
    simulate_percolation(grid);
    print_grid(grid);
    return 0;
}