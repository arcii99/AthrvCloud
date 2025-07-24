//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Cell struct to represent each cell in the grid
typedef struct {
    int row;
    int col;
} Cell;

// Global variables
Cell start, end;    // Start and end cells
char grid[ROWS][COLS] = {
    {'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' ', '#'}
};
int dist[ROWS][COLS] = {0};  // Distance array to track the distance from the start cell to any other cell
bool visited[ROWS][COLS] = {false};  // Visited array to track the cells that have been visited

// Function declarations
bool isValid(Cell c);
bool isWall(Cell c);
void printGrid();
void getPath(Cell path[ROWS*COLS], int* len);
void bfs();

// Main function
int main() {
    // Set start and end cells
    start.row = 0;
    start.col = 1;
    end.row = 9;
    end.col = 5;
    
    // Print initial grid
    printf("Initial Grid:\n");
    printGrid();
    
    // Run BFS to find the shortest path
    bfs();
    
    // Print the shortest path
    Cell path[ROWS*COLS];
    int len = 0;
    getPath(path, &len);
    printf("Shortest Path:\n");
    for (int i = 0; i < len; i++) {
        printf("(%d,%d)", path[i].row, path[i].col);
        if (i != len-1) {
            printf(" -> ");
        }
    }
    
    return 0;
}

// Function to check whether a cell is a valid cell (i.e. within the grid boundaries)
bool isValid(Cell c) {
    return (c.row >= 0 && c.row < ROWS && c.col >= 0 && c.col < COLS);
}

// Function to check whether a cell is a wall
bool isWall(Cell c) {
    return (grid[c.row][c.col] == '#');
}

// Function to print the current state of the grid
void printGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to get the shortest path from the start cell to the end cell using the distance array
void getPath(Cell path[ROWS*COLS], int* len) {
    Cell curr = end;
    while (!(curr.row == start.row && curr.col == start.col)) {
        path[*len] = curr;
        (*len)++;
        int minDist = 9999;
        Cell next;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                Cell adj = {curr.row + i, curr.col + j};
                if (isValid(adj) && dist[adj.row][adj.col] < minDist && dist[adj.row][adj.col] != 0) {
                    minDist = dist[adj.row][adj.col];
                    next = adj;
                }
            }
        }
        curr = next;
    }
    path[*len] = start;
    (*len)++;
}

// Breadth-first search to find the shortest path
void bfs() {
    // Create queue to track cells
    Cell queue[ROWS*COLS];
    int front = 0, rear = 0;
    
    // Add start cell to queue and mark as visited
    queue[rear++] = start;
    visited[start.row][start.col] = true;
    
    // BFS loop
    while (front < rear) {
        // Dequeue a cell
        Cell curr = queue[front++];
        // Check if it's the end cell
        if (curr.row == end.row && curr.col == end.col) {
            break;
        }
        // Explore adjacent cells
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Skip current cell and diagonal cells
                if ((i == 0 && j == 0) || (i != 0 && j != 0)) {
                    continue;
                }
                Cell adj = {curr.row + i, curr.col + j};
                // Check if adjacent cell is a valid cell, not a wall, and not visited
                if (isValid(adj) && !isWall(adj) && !visited[adj.row][adj.col]) {
                    // Enqueue adjacent cell, mark as visited, and update distance array
                    queue[rear++] = adj;
                    visited[adj.row][adj.col] = true;
                    dist[adj.row][adj.col] = dist[curr.row][curr.col] + 1;
                }
            }
        }
    }
}