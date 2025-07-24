//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: future-proof
// A* Pathfinding Algorithm Implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the grid size as constants
#define ROWS 10
#define COLS 10

// Define the start and end point as constants
#define START_ROW 2
#define START_COL 2
#define END_ROW 8
#define END_COL 8

// Define the cell structure
typedef struct {
    int row;
    int col;
    int g_cost;
    int h_cost;
    int f_cost;
    bool is_obstacle;
    bool is_visited;
    bool is_start;
    bool is_end;
    struct Cell* parent;
} Cell;

// Function to calculate the Manhattan distance between two points
int manhattan_distance(int row1, int col1, int row2, int col2) {
    return abs(row1 - row2) + abs(col1 - col2);
}

// Function to initialize the grid
void initialize_grid(Cell grid[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            grid[row][col].row = row;
            grid[row][col].col = col;
            grid[row][col].g_cost = 0;
            grid[row][col].h_cost = manhattan_distance(row, col, END_ROW, END_COL);
            grid[row][col].f_cost = grid[row][col].g_cost + grid[row][col].h_cost;
            grid[row][col].is_obstacle = false;
            grid[row][col].is_visited = false;
            grid[row][col].is_start = (row == START_ROW && col == START_COL);
            grid[row][col].is_end = (row == END_ROW && col == END_COL);
            grid[row][col].parent = NULL;
        }
    }
}

// Function to set the obstacles in the grid
void set_obstacles(Cell grid[ROWS][COLS]) {
    // Set some random cells as obstacles
    grid[1][3].is_obstacle = true;
    grid[2][3].is_obstacle = true;
    grid[3][3].is_obstacle = true;
    grid[4][3].is_obstacle = true;
    grid[5][3].is_obstacle = true;
    grid[6][3].is_obstacle = true;
    grid[7][3].is_obstacle = true;
    grid[8][3].is_obstacle = true;
}

// Function to print the grid
void print_grid(Cell grid[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (grid[row][col].is_obstacle) {
                printf("X ");
            } else if (grid[row][col].is_start) {
                printf("S ");
            } else if (grid[row][col].is_end) {
                printf("E ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to find the cell with the lowest f_cost
Cell* find_lowest_f_cost_cell(Cell grid[ROWS][COLS]) {
    Cell* lowest_f_cost_cell = NULL;
    int lowest_f_cost = -1;
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (!grid[row][col].is_obstacle && !grid[row][col].is_visited) {
                if (lowest_f_cost == -1 || grid[row][col].f_cost < lowest_f_cost) {
                    lowest_f_cost = grid[row][col].f_cost;
                    lowest_f_cost_cell = &grid[row][col];
                }
            }
        }
    }
    return lowest_f_cost_cell;
}

// Function to update the f_cost, g_cost and parent of the neighbours
void update_neighbour_cell(Cell grid[ROWS][COLS], Cell* parent_cell, Cell* neighbour_cell) {
    int new_g_cost = parent_cell->g_cost + manhattan_distance(parent_cell->row, parent_cell->col, neighbour_cell->row, neighbour_cell->col);
    if (new_g_cost < neighbour_cell->g_cost || !neighbour_cell->is_visited) {
        neighbour_cell->g_cost = new_g_cost;
        neighbour_cell->f_cost = neighbour_cell->g_cost + neighbour_cell->h_cost;
        neighbour_cell->parent = parent_cell;
        neighbour_cell->is_visited = true;
    }
}

// Function to find and update the neighbours of the current cell
void update_neighbours(Cell grid[ROWS][COLS], Cell* current_cell) {
    // Define the neighbours
    Cell* neighbour_top = (current_cell->row > 0) ? &grid[current_cell->row - 1][current_cell->col] : NULL;
    Cell* neighbour_bottom = (current_cell->row < ROWS - 1) ? &grid[current_cell->row + 1][current_cell->col] : NULL;
    Cell* neighbour_left = (current_cell->col > 0) ? &grid[current_cell->row][current_cell->col - 1] : NULL;
    Cell* neighbour_right = (current_cell->col < COLS - 1) ? &grid[current_cell->row][current_cell->col + 1] : NULL;
    // Update the neighbours
    if (neighbour_top != NULL) {
        update_neighbour_cell(grid, current_cell, neighbour_top);
    }
    if (neighbour_bottom != NULL) {
        update_neighbour_cell(grid, current_cell, neighbour_bottom);
    }
    if (neighbour_left != NULL) {
        update_neighbour_cell(grid, current_cell, neighbour_left);
    }
    if (neighbour_right != NULL) {
        update_neighbour_cell(grid, current_cell, neighbour_right);
    }
}

// Function to find the path from start to end
void find_path(Cell grid[ROWS][COLS]) {
    Cell* current_cell = &grid[START_ROW][START_COL];
    current_cell->is_visited = true;
    while (current_cell != &grid[END_ROW][END_COL]) {
        update_neighbours(grid, current_cell);
        current_cell = find_lowest_f_cost_cell(grid);
        if (current_cell == NULL) {
            // No path found
            printf("No path found!\n");
            break;
        }
    }
    if (current_cell != NULL) {
        // Print the path
        printf("Path: ");
        while (current_cell->parent != NULL) {
            printf("(%d,%d) ", current_cell->row, current_cell->col);
            current_cell = current_cell->parent;
        }
        printf("(%d,%d)\n", current_cell->row, current_cell->col);
    }
}

// The main function
int main() {
    // Initialize the grid
    Cell grid[ROWS][COLS];
    initialize_grid(grid);
    // Set the obstacles in the grid
    set_obstacles(grid);
    // Print the grid
    printf("Grid:\n");
    print_grid(grid);
    // Find the path from start to end
    find_path(grid);
    return 0;
}