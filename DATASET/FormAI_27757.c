//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 8

// The grid we will use for testing the algorithm
int grid[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// Struct to hold coordinates of a cell
typedef struct {
    int row;
    int col;
} Cell;

// Struct to hold information for priority queue
typedef struct {
    Cell cell;
    int f;
} Node;

// Function to check if a cell is within the bounds of the grid
bool in_bounds(Cell cell) {
    return cell.row >= 0 && cell.row < ROWS && cell.col >= 0 && cell.col < COLS;
}

// Function to check if a cell is walkable (0 means walkable, anything else means not walkable)
bool walkable(Cell cell) {
    return grid[cell.row][cell.col] == 0;
}

// Function to get the heuristic value (Manhattan distance)
int heuristic(Cell from, Cell to) {
    return abs(from.row - to.row) + abs(from.col - to.col);
}

// Function to get the neighbors of a cell
Cell* get_neighbors(Cell cell) {
    static Cell neighbors[8];
    neighbors[0] = (Cell) {cell.row - 1, cell.col - 1};
    neighbors[1] = (Cell) {cell.row - 1, cell.col};
    neighbors[2] = (Cell) {cell.row - 1, cell.col + 1};
    neighbors[3] = (Cell) {cell.row, cell.col - 1};
    neighbors[4] = (Cell) {cell.row, cell.col + 1};
    neighbors[5] = (Cell) {cell.row + 1, cell.col - 1};
    neighbors[6] = (Cell) {cell.row + 1, cell.col};
    neighbors[7] = (Cell) {cell.row + 1, cell.col + 1};

    for (int i = 0; i < 8; i++) {
        if (!in_bounds(neighbors[i]) || !walkable(neighbors[i])) {
            neighbors[i] = (Cell) {-1, -1};
        }
    }

    return neighbors;
}

// Function to get the path from start to end using A* algorithm
Cell* get_path(Cell start, Cell end) {
    // Create priority queue and add starting node
    Node open_list[ROWS * COLS] = {[0].cell = start, [0].f = heuristic(start, end)};
    int open_len = 1;

    // Create closed list
    bool closed_list[ROWS][COLS] = {false};

    while (open_len > 0) {
        // Find node with lowest f value
        int lowest_f = open_list[0].f;
        int lowest_i = 0;
        for (int i = 0; i < open_len; i++) {
            if (open_list[i].f < lowest_f) {
                lowest_f = open_list[i].f;
                lowest_i = i;
            }
        }

        // Get node with lowest f value
        Node current_node = open_list[lowest_i];
        Cell current_cell = current_node.cell;

        // Remove node from open list
        open_list[lowest_i] = open_list[open_len - 1];
        open_len--;

        // Check if current cell is the end cell
        if (current_cell.row == end.row && current_cell.col == end.col) {
            // Trace back path and return it
            static Cell path[ROWS * COLS];
            int path_len = 0;

            Cell cell = current_cell;
            while (cell.row != start.row || cell.col != start.col) {
                path[path_len] = cell;
                path_len++;

                cell = current_node.cell;
                for (int i = 0; i < open_len; i++) {
                    if (open_list[i].cell.row == cell.row && open_list[i].cell.col == cell.col) {
                        current_node = open_list[i];
                        break;
                    }
                }
			}
            path[path_len] = cell;

            return path;
        }

        // Add current cell to closed list
        closed_list[current_cell.row][current_cell.col] = true;

        // Process neighbors
        Cell* neighbors = get_neighbors(current_cell);
        for (int i = 0; i < 8; i++) {
            Cell neighbor = neighbors[i];
            if (neighbor.row == -1 || closed_list[neighbor.row][neighbor.col]) {
                continue;
            }

            // Calculate f, g, and h values for neighbor
            int g = current_node.f - heuristic(current_cell, end) + 1;
            int h = heuristic(neighbor, end);
            int f = g + h;

            // Add neighbor to open list if not already in it
            bool neighbor_in_open_list = false;
            for (int i = 0; i < open_len; i++) {
                if (open_list[i].cell.row == neighbor.row && open_list[i].cell.col == neighbor.col) {
                    neighbor_in_open_list = true;
                    if (f < open_list[i].f) {
                        open_list[i].f = f;
                    }
                    break;
                }
            }
            if (!neighbor_in_open_list) {
                open_list[open_len] = (Node) {.cell = neighbor, .f = f};
                open_len++;
            }
        }
    }

    // If no path was found, return null
    return NULL;
}

int main() {
	// Set start and end cells
	Cell start = {0, 0};
	Cell end = {5, 7};

	// Set up obstacles in the grid
	grid[2][2] = 1;
	grid[3][2] = 1;
	grid[4][2] = 1;

	// Get path from start to end
	Cell* path = get_path(start, end);

	// Print out path
	if (path == NULL) {
		printf("No path found\n");
	} else {
		for (int i = 0; path[i].row != -1 && path[i].col != -1; i++) {
			printf("(%d, %d) -> ", path[i].row, path[i].col);
		}
		printf("\n");
	}

	return 0;
}