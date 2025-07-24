//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

// Struct to represent a cell in the grid
struct Cell {
    int row;
    int col;
};

// Function to find the path between the start and end cell using BFS
bool bfs(int grid[][COL], struct Cell start, struct Cell end, struct Cell parent[][COL]) {
    // Visited array to keep track of visited cells
    bool visited[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }

    // Queue to store the cells to visit
    struct Cell queue[ROW * COL];
    int front = -1, rear = -1;

    // Add the start cell to the queue
    queue[++rear] = start;
    visited[start.row][start.col] = true;
    parent[start.row][start.col] = start;
 
    // Loop until the queue is empty
    while (front != rear) {
        // Remove the next cell from the queue
        struct Cell curr = queue[++front];

        // Check if we have reached the end cell
        if (curr.row == end.row && curr.col == end.col) {
            return true;
        }

        // Check the neighbors of the current cell
        int row = curr.row, col = curr.col;
        if (row > 0 && grid[row-1][col] != 1 && !visited[row-1][col]) {  // Up
            visited[row-1][col] = true;
            struct Cell next = {row-1, col};
            queue[++rear] = next;
            parent[row-1][col] = curr;
        }
        if (col < COL-1 && grid[row][col+1] != 1 && !visited[row][col+1]) {  // Right
            visited[row][col+1] = true;
            struct Cell next = {row, col+1};
            queue[++rear] = next;
            parent[row][col+1] = curr;
        }
        if (row < ROW-1 && grid[row+1][col] != 1 && !visited[row+1][col]) {  // Down
            visited[row+1][col] = true;
            struct Cell next = {row+1, col};
            queue[++rear] = next;
            parent[row+1][col] = curr;
        }
        if (col > 0 && grid[row][col-1] != 1 && !visited[row][col-1]) {  // Left
            visited[row][col-1] = true;
            struct Cell next = {row, col-1};
            queue[++rear] = next;
            parent[row][col-1] = curr;
        }
    }

    // If we reach here, there is no path from start to end
    return false;
}

// Function to print the path from start to end
void printPath(struct Cell parent[][COL], struct Cell start, struct Cell end) {
    struct Cell path[ROW*COL];
    int index = 0;

    // Follow the parent pointers from end to start
    struct Cell curr = end;
    while (curr.row != start.row || curr.col != start.col) {
        path[index++] = curr;
        curr = parent[curr.row][curr.col];
    }
    path[index] = start;

    // Print the path in reverse order
    for (int i = index; i >= 0; i--) {
        printf("(%d,%d)", path[i].row, path[i].col);
        if (i != 0) {
            printf(" --> ");
        }
    }
    printf("\n");
}

int main() {
    int grid[ROW][COL] = {{0, 1, 1, 0, 0},
                          {0, 0, 0, 1, 0},
                          {1, 1, 0, 0, 0},
                          {1, 1, 1, 0, 0},
                          {1, 1, 1, 0, 0}};
    struct Cell start = {0, 0};
    struct Cell end = {4, 4};
    struct Cell parent[ROW][COL];

    // Find the path from start to end
    bool foundPath = bfs(grid, start, end, parent);
    if (foundPath) {
        printf("Path found: ");
        printPath(parent, start, end);
    } else {
        printf("No path found\n");
    }

    return 0;
}