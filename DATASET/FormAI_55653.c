//FormAI DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 30
#define HEIGHT 30

// Initialize the grid
void initialize(int grid[][WIDTH])
{
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            grid[i][j]  = rand() % 2;
        }
    }
}

// Print the grid
void print_grid(int grid[][WIDTH])
{
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Count the number of live neighbours for a given cell
int count_live_neighbours(int grid[][WIDTH], int x, int y)
{
    int i, j, live_count = 0;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (x + i < 0 || x + i >= HEIGHT) {
                continue;
            }
            if (y + j < 0 || y + j >= WIDTH) {
                continue;
            }
            if (grid[x + i][y + j] == 1) {
                live_count++;
            }
        }
    }
    return live_count;
}

// Update the grid based on the rules of the game
void update_grid(int grid[][WIDTH])
{
    int i, j, neighbours;

    // Create a copy of the grid
    int new_grid[HEIGHT][WIDTH];
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            new_grid[i][j] = grid[i][j];
        }
    }

    // Apply the rules of the game
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            neighbours = count_live_neighbours(grid, i, j);
            if (grid[i][j] == 1) {
                if (neighbours < 2 || neighbours > 3) {
                    new_grid[i][j] = 0;
                }
            } else {
                if (neighbours == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
    }

    // Update the grid with the new state
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main()
{
    int grid[HEIGHT][WIDTH];
    initialize(grid);

    // Run the game for 50 steps
    int i;
    for (i = 0; i < 50; i++) {
        printf("Step %d:\n", i + 1);
        print_grid(grid);
        update_grid(grid);
    }
    return 0;
}