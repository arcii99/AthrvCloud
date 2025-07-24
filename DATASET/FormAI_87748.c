//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// Structure for holding the coordinates of each cell in the grid
struct cell {
    int row;
    int col;
};

// Structure for holding the path
struct path {
    struct cell cells[ROW * COL];
    int size;
};

// Function for checking if the given cell is valid or not
bool isValid(int grid[][COL], int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (grid[row][col] == 0);
}

// Function for checking if the given cell is the destination or not
bool isDestination(int row, int col, struct cell dest) {
    return (row == dest.row && col == dest.col);
}

// Function for printing the given path
void printPath(struct path p) {
    for (int i = 0; i < p.size; i++) {
        printf("(%d, %d) ", p.cells[i].row, p.cells[i].col);
    }
    printf("\n");
}

// Function for finding the shortest path using depth first search algorithm
void dfs(int grid[][COL], int row, int col, struct cell dest, struct path* p, struct path* shortestPath) {
    // If the current cell is the destination, check if the current path is shortest
    if (isDestination(row, col, dest)) {
        if (shortestPath->size == 0 || p->size < shortestPath->size) {
            shortestPath->size = p->size;
            for (int i = 0; i < p->size; i++) {
                shortestPath->cells[i] = p->cells[i];
            }
        }
        return;
    }

    // Mark the current cell as visited
    grid[row][col] = 1;

    // Check and explore all the adjacent cells
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];
        if (isValid(grid, newRow, newCol)) {
            // Add the current cell to the path
            p->cells[p->size].row = row;
            p->cells[p->size].col = col;
            p->size++;
            // Recursively explore the adjacent cells
            dfs(grid, newRow, newCol, dest, p, shortestPath);
            // Remove the current cell from the path
            p->size--;
        }
    }

    // Mark the current cell as unvisited
    grid[row][col] = 0;
}

// Function for finding the shortest path using depth first search algorithm
void dfsShortestPath(int grid[][COL], struct cell src, struct cell dest) {
    struct path p = {{0}, 0};
    struct path shortestPath = {{0}, 0};
    dfs(grid, src.row, src.col, dest, &p, &shortestPath);
    if (shortestPath.size == 0) {
        printf("No path found!\n");
    } else {
        printf("Shortest path: ");
        printPath(shortestPath);
    }
}

int main() {
    // Define the grid
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    // Define the source and destination cells
    struct cell src = {1, 1};
    struct cell dest = {8, 8};

    // Find the shortest path using depth first search algorithm
    dfsShortestPath(grid, src, dest);

    return 0;
}