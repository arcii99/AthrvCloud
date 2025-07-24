//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

// Define the number of rows and columns in the grid
#define ROWS 5
#define COLS 5

// Structure to hold the position of each cell in the grid
typedef struct {
    int row;
    int col;
} Position;

// Definition of a cell in the grid
typedef struct {
    int value;      // The value of the cell
    bool visited;   // Whether the cell has been visited
    Position prev;  // The previous cell in the path
} Cell;

// The grid of cells
Cell grid[ROWS][COLS];

// The starting and ending positions
Position start = {0, 0};
Position end = {ROWS-1, COLS-1};

// Mutex to synchronize the access to the grid
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to get the neighbors of a cell
void get_neighbors(Position p, Position neighbors[4], int* count) {
    *count = 0;
    if (p.row > 0) {
        neighbors[*count] = (Position){p.row - 1, p.col};
        (*count)++;
    }
    if (p.row < ROWS - 1) {
        neighbors[*count] = (Position){p.row + 1, p.col};
        (*count)++;
    }
    if (p.col > 0) {
        neighbors[*count] = (Position){p.row, p.col - 1};
        (*count)++;
    }
    if (p.col < COLS - 1) {
        neighbors[*count] = (Position){p.row, p.col + 1};
        (*count)++;
    }
}

// Function to check if a position is valid
bool is_valid(Position p) {
    return p.row >= 0 && p.row < ROWS && p.col >= 0 && p.col < COLS && grid[p.row][p.col].value == 0 && !grid[p.row][p.col].visited;
}

// Function to find a path from the start to the end
void find_path(Position p) {
    // If we reached the end position, print the path and return
    if (p.row == end.row && p.col == end.col) {
        printf("(%d,%d)", p.row, p.col);
        Position prev = grid[p.row][p.col].prev;
        while (prev.row != start.row || prev.col != start.col) {
            printf(" -> (%d,%d)", prev.row, prev.col);
            prev = grid[prev.row][prev.col].prev;
        }
        printf(" -> (%d,%d)\n", start.row, start.col);
        return;
    }

    // Mark the cell as visited
    grid[p.row][p.col].visited = true;

    // Get the neighbors of the cell
    Position neighbors[4];
    int count;
    get_neighbors(p, neighbors, &count);

    // Try to find a path from each neighbor
    for (int i = 0; i < count; i++) {
        if (is_valid(neighbors[i])) {
            // Lock the mutex to access the grid
            pthread_mutex_lock(&mutex);

            // Update the previous cell of the neighbor
            grid[neighbors[i].row][neighbors[i].col].prev = p;

            // Unlock the mutex
            pthread_mutex_unlock(&mutex);

            // Recursively find the path from the neighbor
            find_path(neighbors[i]);

            // Lock the mutex to access the grid
            pthread_mutex_lock(&mutex);

            // Mark the neighbor as unvisited so that we can try another path from it later
            grid[neighbors[i].row][neighbors[i].col].visited = false;

            // Unlock the mutex
            pthread_mutex_unlock(&mutex);
        }
    }
}

// Main function to initialize the grid and start the pathfinding
int main() {
    // Initialize the grid with some obstacles
    grid[1][1].value = 1;
    grid[1][2].value = 1;
    grid[2][2].value = 1;
    grid[3][2].value = 1;
    grid[3][3].value = 1;

    // Start the pathfinding from the start position
    find_path(start);

    return 0;
}