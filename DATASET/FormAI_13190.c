//FormAI DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
// Ada Lovelace's Game of Life in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

// Initialize the grid with random values
void initialize_grid(int grid[ROWS][COLS]) {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Print the grid to the console
void print_grid(int grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Count the number of live neighbors around a cell
int count_neighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int neighbor_row = row + i;
            int neighbor_col = col + j;
            if(neighbor_row < 0) {
                neighbor_row = ROWS - 1;
            } else if(neighbor_row >= ROWS) {
                neighbor_row = 0;
            }
            if(neighbor_col < 0) {
                neighbor_col = COLS - 1;
            } else if(neighbor_col >= COLS) {
                neighbor_col = 0;
            }
            count += grid[neighbor_row][neighbor_col];
        }
    }
    count -= grid[row][col];
    return count;
}

// Update the grid according to the rules of the Game of Life
void update_grid(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if(grid[i][j] == 1 && neighbors < 2) {
                new_grid[i][j] = 0;
            } else if(grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_grid[i][j] = 1;
            } else if(grid[i][j] == 1 && neighbors > 3) {
                new_grid[i][j] = 0;
            } else if(grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
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

// Main function
int main() {
    int grid[ROWS][COLS];
    initialize_grid(grid);
    while(1) {
        print_grid(grid);
        update_grid(grid);
        printf("\n");
        system("sleep 0.1"); // Delay to make the animation visible
        system("clear"); // Clear the console before printing the next frame
    }
    return 0;
}