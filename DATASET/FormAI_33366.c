//FormAI DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20
#define NUM_GENERATIONS 50

int grid[GRID_SIZE][GRID_SIZE];

/* Function to initialize the grid with random values */
void initialize_grid() {
    srand(time(NULL)); // seed the random generator

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2; // set value to either 0 or 1
        }
    }
}

/* Function to print the grid */
void print_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c", (grid[i][j] == 0) ? ' ' : '*'); // print space or asterisk
        }
        printf("\n");
    }
}

/* Function to count the number of live neighbors of a cell */
int count_live_neighbors(int row, int col) {
    int live_neighbors = 0;

    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            if (i >= 0 && i < GRID_SIZE && j >= 0 && j < GRID_SIZE && !(i == row && j == col)) {
                live_neighbors += grid[i][j];
            }
        }
    }

    return live_neighbors;
}

/* Function to calculate the next generation of the grid */
void next_generation() {
    int new_grid[GRID_SIZE][GRID_SIZE];

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int live_neighbors = count_live_neighbors(i, j);

            if (grid[i][j] == 0 && live_neighbors == 3) { // dead cell with 3 live neighbors, becomes alive
                new_grid[i][j] = 1;
            } else if (grid[i][j] == 1 && (live_neighbors < 2 || live_neighbors > 3)) { // alive cell with less than 2 or more than 3 live neighbors, dies
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = grid[i][j]; // cell remains the same
            }
        }
    }

    // copy new grid back to old grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    initialize_grid();

    for (int i = 0; i < NUM_GENERATIONS; i++) {
        printf("Generation %d:\n", i+1);
        print_grid();
        next_generation();
    }

    return 0;
}