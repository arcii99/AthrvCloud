//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

// Define cell as a struct consisting of coordinates (x, y) and a flag indicating whether the cell is open or blocked.
typedef struct {
    int x;
    int y;
    int open;
} cell;

// Define a 2D array to represent the grid of cells.
cell cells[GRID_SIZE][GRID_SIZE];

// Initialize the list of neighboring cells for a given cell.
void get_neighboring_cells(cell c, cell neighbors[]) {
    int i = 0;

    // Check if neighbor above current cell is present within grid bounds and is open
    if ((c.y > 0) && cells[c.x][c.y - 1].open) {
        neighbors[i] = cells[c.x][c.y - 1];
        i++;
    }

    // Check if neighbor below current cell is present within grid bounds and is open
    if ((c.y < (GRID_SIZE - 1)) && cells[c.x][c.y + 1].open) {
        neighbors[i] = cells[c.x][c.y + 1];
        i++;
    }

    // Check if neighbor left of current cell is present within grid bounds and is open
    if ((c.x > 0) && cells[c.x - 1][c.y].open) {
        neighbors[i] = cells[c.x - 1][c.y];
        i++;
    }

    // Check if neighbor right of current cell is present within grid bounds and is open
    if ((c.x < (GRID_SIZE - 1)) && cells[c.x + 1][c.y].open) {
        neighbors[i] = cells[c.x + 1][c.y];
        i++;
    }
}

// Check if the system percolates
int does_percolate() {
    // Initialize the top and bottom grid boundary flags to false.
    int top_open = 0;
    int bottom_open = 0;

    // Check if any cell on the top boundary is open.
    for (int i = 0; i < GRID_SIZE; i++) {
        if (cells[i][0].open) {
            top_open = 1;
            break;
        }
    }

    // Check if any cell on the bottom boundary is open.
    for (int i = 0; i < GRID_SIZE; i++) {
        if (cells[i][GRID_SIZE - 1].open) {
            bottom_open = 1;
            break;
        }
    }

    return (top_open && bottom_open);
}

// Open a random cell in the grid
void open_random_cell() {
    int x, y;

    // Repeat until a cell has been opened.
    do {
        // Generate random coordinates within the grid size.
        x = rand() % GRID_SIZE;
        y = rand() % GRID_SIZE;
    } while (cells[x][y].open);

    // Open the cell at the generated coordinates.
    cells[x][y].open = 1;
}

// Print the grid of cells to the console.
void print_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (cells[i][j].open) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Seed the random number generator with the current time.
    srand(time(NULL));

    // Initialize all cells as closed.
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            cells[i][j].x = i;
            cells[i][j].y = j;
            cells[i][j].open = 0;
        }
    }

    // Open cells randomly until the system percolates.
    while (!does_percolate()) {
        open_random_cell();
    }

    // Print the final grid of cells.
    print_grid();

    return 0;
}