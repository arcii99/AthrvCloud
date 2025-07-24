//FormAI DATASET v1.0 Category: Game of Life ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// Function to display the grid
void display_grid(int grid[ROWS][COLS]) {
    printf("============================\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 1) {
                printf("* ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to generate a random grid
void randomize_grid(int grid[ROWS][COLS]) {
    srand(time(0));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to count the number of neighbors of a cell
int count_neighbors(int grid[ROWS][COLS], int x, int y) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int neighbor_x = x + i;
            int neighbor_y = y + j;
            if(neighbor_x >= 0 && neighbor_x < ROWS && neighbor_y >= 0 && neighbor_y < COLS && !(i == 0 && j == 0)) {
                count += grid[neighbor_x][neighbor_y];
            }
        }
    }
    return count;
}

// Function to run a single step of the simulation
void run_simulation(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS] = {0};
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int num_neighbors = count_neighbors(grid, i, j);
            if(grid[i][j] == 1 && (num_neighbors < 2 || num_neighbors > 3)) {
                new_grid[i][j] = 0;
            }
            else if(grid[i][j] == 0 && num_neighbors == 3) {
                new_grid[i][j] = 1;
            }
            else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS] = {0};
    randomize_grid(grid);
    display_grid(grid);
    for(int i = 0; i < 100; i++) {
        run_simulation(grid);
        display_grid(grid);
    }
    return 0;
}