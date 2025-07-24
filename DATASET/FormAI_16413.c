//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for grid size and probability
#define GRID_SIZE 10
#define PROBABILITY 0.5

// Enum to represent cell states
typedef enum {
    BLOCKED,
    OPEN,
    CONNECTED
} CellState;

// Struct to hold cell state and parent index
typedef struct {
    CellState state;
    int parent;
} Cell;

// Function to check if a cell is in the top row
int in_top_row(int index) {
    return (index < GRID_SIZE);
}

// Function to check if a cell is in the bottom row
int in_bottom_row(int index) {
    return (index >= GRID_SIZE * (GRID_SIZE - 1));
}

// Function to initialize grid with blocked cells
void initialize_grid(Cell *grid) {
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        grid[i].state = BLOCKED;
        grid[i].parent = -1;
    }
}

// Function to randomly open cells in the grid
void percolate(Cell *grid) {
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        if ((double)rand() / RAND_MAX < PROBABILITY) {
            grid[i].state = OPEN;
        }
    }
}

// Function to check if two cells are connected
int is_connected(Cell *grid, int index1, int index2) {
    if (grid[index1].state == OPEN && grid[index2].state == OPEN) {
        while (grid[index1].parent >= 0) {
            index1 = grid[index1].parent;
        }
        while (grid[index2].parent >= 0) {
            index2 = grid[index2].parent;
        }
        return (index1 == index2);
    }
    return 0;
}

// Function to connect two cells
void connect(Cell *grid, int index1, int index2) {
    while (grid[index1].parent >= 0) {
        index1 = grid[index1].parent;
    }
    while (grid[index2].parent >= 0) {
        index2 = grid[index2].parent;
    }
    if (index1 != index2) {
        if (grid[index1].parent > grid[index2].parent) {
            grid[index2].parent += grid[index1].parent;
            grid[index1].parent = index2;
        } else {
            grid[index1].parent += grid[index2].parent;
            grid[index2].parent = index1;
        }
    }
}

// Function to connect cells in the grid
void connect_cells(Cell *grid) {
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        if (grid[i].state == OPEN) {
            if (!in_top_row(i)) {
                if (grid[i - GRID_SIZE].state == OPEN) {
                    connect(grid, i, i - GRID_SIZE);
                }
            } else {
                grid[i].parent = -1;
            }
            if (!in_bottom_row(i)) {
                if (grid[i + GRID_SIZE].state == OPEN) {
                    connect(grid, i, i + GRID_SIZE);
                }
            }
            if (i % GRID_SIZE != 0) {
                if (grid[i - 1].state == OPEN) {
                    connect(grid, i, i - 1);
                }
            }
            if ((i + 1) % GRID_SIZE != 0) {
                if (grid[i + 1].state == OPEN) {
                    connect(grid, i, i + 1);
                }
            }
        }
    }
}

// Function to check if the grid percolates
int percolates(Cell *grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i].state == OPEN && grid[i].parent < 0) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));
    // Create grid
    Cell grid[GRID_SIZE * GRID_SIZE];
    // Initialize grid with blocked cells
    initialize_grid(grid);
    // Randomly open cells in the grid
    percolate(grid);
    // Connect cells in the grid
    connect_cells(grid);
    // Check if the grid percolates
    if (percolates(grid)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate :(\n");
    }
    // Exit program
    return 0;
}