//FormAI DATASET v1.0 Category: Data structures visualization ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

// Data structure to represent a cell in the grid
typedef struct Cell {
    int value;
    int visited;
} Cell;

// Data structure to represent the grid
typedef struct Grid {
    Cell cells[ROWS][COLUMNS];
} Grid;

// Function to initialize the grid
void init_grid(Grid *grid) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            grid->cells[i][j].value = rand() % 10; // Random value between 0 and 9
            grid->cells[i][j].visited = 0;
        }
    }
}

// Function to print the grid
void print_grid(Grid *grid) {
    int i, j;

    printf("   ");
    for (i = 0; i < COLUMNS; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (i = 0; i < ROWS; i++) {
        printf("%2d ", i);
        for (j = 0; j < COLUMNS; j++) {
            if (grid->cells[i][j].visited) {
                printf("[#]"); // Cell has been visited
            }
            else {
                printf("[%d]", grid->cells[i][j].value);
            }
        }
        printf("\n");
    }
}

// Recursive function to traverse the grid
void traverse_grid(Grid *grid, int x, int y) {
    grid->cells[x][y].visited = 1;

    if (x > 0 && !grid->cells[x-1][y].visited) {
        traverse_grid(grid, x-1, y); // Traverse left
    }
    if (x < ROWS-1 && !grid->cells[x+1][y].visited) {
        traverse_grid(grid, x+1, y); // Traverse right
    }
    if (y > 0 && !grid->cells[x][y-1].visited) {
        traverse_grid(grid, x, y-1); // Traverse up
    }
    if (y < COLUMNS-1 && !grid->cells[x][y+1].visited) {
        traverse_grid(grid, x, y+1); // Traverse down
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Grid grid;
    init_grid(&grid);
    print_grid(&grid);

    int x = rand() % ROWS; // Random row
    int y = rand() % COLUMNS; // Random column
    printf("Starting cell: (%d,%d)\n\n", x, y);

    traverse_grid(&grid, x, y);
    printf("\n");
    print_grid(&grid);

    return 0;
}