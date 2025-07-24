//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: single-threaded
#include <stdio.h>
#define ROW_SIZE 5
#define COL_SIZE 5

// Create a struct to represent each cell in the grid
typedef struct {
    int row;
    int col;
    int distance; // distance from source
    int visited; // 0 if not visited, 1 if visited
} cell;

// Function to determine if cell is valid (within grid and unvisited)
int is_valid(int row, int col, int visited[][COL_SIZE]) {
    return (row >= 0) &&
           (row < ROW_SIZE) &&
           (col >= 0) &&
           (col < COL_SIZE) &&
           !visited[row][col];
}

// Function to find shortest path from source cell to destination cell
void shortest_path(int grid[][COL_SIZE], cell source, cell dest) {
    // Create queue to hold cells to be visited
    cell queue[ROW_SIZE * COL_SIZE];
    int front = 0, rear = 0;
    // Mark source cell as visited and add to queue
    source.visited = 1;
    queue[rear++] = source;
    // Create 2D array to keep track of visited cells
    int visited[ROW_SIZE][COL_SIZE];
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            visited[i][j] = 0;
        }
    }
    visited[source.row][source.col] = 1;
    // Create array to keep track of distances from source
    int distances[ROW_SIZE][COL_SIZE];
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            distances[i][j] = -1;
        }
    }
    distances[source.row][source.col] = 0;
    // Traverse through grid using BFS algorithm
    while (front < rear) {
        cell curr = queue[front++];
        // Return distance if destination cell is found
        if (curr.row == dest.row && curr.col == dest.col) {
            printf("Shortest path from source to destination: %d", distances[curr.row][curr.col]);
            return;
        }
        // Explore neighbors of current cell and add to queue
        if (is_valid(curr.row-1, curr.col, visited)) { // up
            visited[curr.row-1][curr.col] = 1;
            distances[curr.row-1][curr.col] = curr.distance + 1;
            queue[rear++] = (cell) {curr.row-1, curr.col, curr.distance+1, 1};
        }
        if (is_valid(curr.row+1, curr.col, visited)) { // down
            visited[curr.row+1][curr.col] = 1;
            distances[curr.row+1][curr.col] = curr.distance + 1;
            queue[rear++] = (cell) {curr.row+1, curr.col, curr.distance+1, 1};
        }
        if (is_valid(curr.row, curr.col-1, visited)) { // left
            visited[curr.row][curr.col-1] = 1;
            distances[curr.row][curr.col-1] = curr.distance + 1;
            queue[rear++] = (cell) {curr.row, curr.col-1, curr.distance+1, 1};
        }
        if (is_valid(curr.row, curr.col+1, visited)) { // right
            visited[curr.row][curr.col+1] = 1;
            distances[curr.row][curr.col+1] = curr.distance + 1;
            queue[rear++] = (cell) {curr.row, curr.col+1, curr.distance+1, 1};
        }
    }
    // If destination cell is not found
    printf("Shortest path could not be found.");
}

int main() {
    // Example input grid
    int grid[ROW_SIZE][COL_SIZE] = {{1, 1, 1, 1, 1},
                                     {0, 0, 1, 0, 1},
                                     {1, 1, 1, 0, 1},
                                     {0, 0, 0, 0, 1},
                                     {1, 1, 1, 0, 1}};
    // Create source and destination cells
    cell source = {0, 0, 0, 0};
    cell dest = {ROW_SIZE-1, COL_SIZE-1, 0, 0};
    // Find shortest path from source to destination
    shortest_path(grid, source, dest);
    return 0;
}