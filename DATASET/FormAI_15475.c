//FormAI DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define ROWS 20
#define COLS 40

// Define the maximum number of generations to simulate
#define MAX_GENERATIONS 1000

// Define the cell states
#define DEAD '.'
#define ALIVE '*'

// Define the neighbor directions
#define NW -1, -1
#define N  -1,  0
#define NE -1,  1
#define W   0, -1
#define E   0,  1
#define SW  1, -1
#define S   1,  0
#define SE  1,  1

// Define the grid array and a temporary copy for updates
char grid[ROWS][COLS];
char temp[ROWS][COLS];

// Function to initialize the grid with random cell states
void init_grid() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2 ? ALIVE : DEAD;
        }
    }
}

// Function to print the current state of the grid
void print_grid() {
    printf("Generation:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to count the number of alive neighbors for a cell
int count_neighbors(int x, int y) {
    int count = 0;
    if (x > 0) {
        if (y > 0 && grid[x+NW] == ALIVE) count++;
        if (grid[x+N] == ALIVE) count++;
        if (y < COLS-1 && grid[x+NE] == ALIVE) count++;
    }
    if (y > 0 && grid[x+W] == ALIVE) count++;
    if (y < COLS-1 && grid[x+E] == ALIVE) count++;
    if (x < ROWS-1) {
        if (y > 0 && grid[x+SW] == ALIVE) count++;
        if (grid[x+S] == ALIVE) count++;
        if (y < COLS-1 && grid[x+SE] == ALIVE) count++;
    }
    return count;
}

// Function to simulate a single generation of the game of life
void simulate() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(i, j);
            if (grid[i][j] == ALIVE) {
                if (neighbors < 2 || neighbors > 3) {
                    temp[i][j] = DEAD;
                } else {
                    temp[i][j] = ALIVE;
                }
            } else {
                if (neighbors == 3) {
                    temp[i][j] = ALIVE;
                } else {
                    temp[i][j] = DEAD;
                }
            }
        }
    }
    // Copy the updated grid to the original grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

int main() {
    // Initialize the grid and print the first generation
    init_grid();
    print_grid();

    // Simulate a fixed number of generations
    for (int generation = 1; generation <= MAX_GENERATIONS; generation++) {
        simulate();
        printf("\nGeneration %d:\n", generation);
        print_grid();
    }

    return 0;
}