//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the maze dimensions
#define ROWS 20
#define COLS 20

// Constants for maze cell states
#define CELL_WALL 0
#define CELL_OPEN 1

// Helper function to randomly choose a direction
int get_random_direction() {
    return rand() % 4;
}

// Helper function to check if a cell is within the maze
int is_valid_cell(int row, int col) {
    return (row >= 0 && row < ROWS) && (col >= 0 && col < COLS);
}

// Helper function to check if a cell has unvisited neighbors
int has_unvisited_neighbors(int cells[ROWS][COLS], int row, int col) {
    int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < 4; i++) {
        int neighbor_row = row + neighbors[i][0];
        int neighbor_col = col + neighbors[i][1];

        if (is_valid_cell(neighbor_row, neighbor_col) && cells[neighbor_row][neighbor_col] == CELL_WALL) {
            return 1;
        }
    }

    return 0;
}

// Function to generate the maze using a depth-first search algorithm
void generate_maze(int cells[ROWS][COLS], int start_row, int start_col) {
    // Mark the current cell as visited
    cells[start_row][start_col] = CELL_OPEN;

    // Check for unvisited neighbors and choose a random one to visit
    while (has_unvisited_neighbors(cells, start_row, start_col)) {
        int direction = get_random_direction();
        int next_row = start_row;
        int next_col = start_col;

        switch (direction) {
            case 0:
                next_row--;
                break;
            case 1:
                next_row++;
                break;
            case 2:
                next_col--;
                break;
            case 3:
                next_col++;
                break;
        }

        if (is_valid_cell(next_row, next_col) && cells[next_row][next_col] == CELL_WALL) {
            // Carve a path in the chosen direction
            if (direction == 0) {
                cells[start_row-1][start_col] = CELL_OPEN;
            } else if (direction == 1) {
                cells[start_row+1][start_col] = CELL_OPEN;
            } else if (direction == 2) {
                cells[start_row][start_col-1] = CELL_OPEN;
            } else if (direction == 3) {
                cells[start_row][start_col+1] = CELL_OPEN;
            }

            // Recursively generate the rest of the maze from the newly-visited cell
            generate_maze(cells, next_row, next_col);
        }
    }
}

// Function to print the maze as ASCII art
void print_maze(int cells[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (cells[row][col] == CELL_WALL) {
                printf("#");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
}

int main() {
    int cells[ROWS][COLS] = {0};
    srand(time(NULL));

    // Generate the maze starting from the top-left corner
    generate_maze(cells, 0, 0);

    // Print the generated maze
    print_maze(cells);

    return 0;
}