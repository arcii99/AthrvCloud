//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

// Node structure to hold coordinates
typedef struct Node {
    int row, col;
    struct Node* next;
} Node;

// Function to add a new coordinate to the path
Node* addCoord(Node* path, int row, int col) {
    Node* newNode = malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->next = path;
    return newNode;
}

// Function to check if a coordinate is valid and unvisited
int isValid(int row, int col, int visited[ROWS][COLS]) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && visited[row][col] == 0);
}

// Recursive function to find the shortest path
Node* findPath(int maze[ROWS][COLS], int visited[ROWS][COLS], int row, int col, int targetRow, int targetCol) {
    if (row == targetRow && col == targetCol) {
        // Base case: reached the target, return a path with only the target coordinate
        return addCoord(NULL, row, col);
    } else {
        // Recursive case: try all four directions
        visited[row][col] = 1;
        if (isValid(row-1, col, visited) && maze[row-1][col] == 0) {
            Node* path = findPath(maze, visited, row-1, col, targetRow, targetCol);
            if (path != NULL) {
                // Found a path, add current coordinate and return
                return addCoord(path, row, col);
            }
        }
        if (isValid(row+1, col, visited) && maze[row+1][col] == 0) {
            Node* path = findPath(maze, visited, row+1, col, targetRow, targetCol);
            if (path != NULL) {
                // Found a path, add current coordinate and return
                return addCoord(path, row, col);
            }
        }
        if (isValid(row, col-1, visited) && maze[row][col-1] == 0) {
            Node* path = findPath(maze, visited, row, col-1, targetRow, targetCol);
            if (path != NULL) {
                // Found a path, add current coordinate and return
                return addCoord(path, row, col);
            }
        }
        if (isValid(row, col+1, visited) && maze[row][col+1] == 0) {
            Node* path = findPath(maze, visited, row, col+1, targetRow, targetCol);
            if (path != NULL) {
                // Found a path, add current coordinate and return
                return addCoord(path, row, col);
            }
        }
        visited[row][col] = 0;
        // No path found, return NULL
        return NULL;
    }
}

int main() {
    // Example maze and target coordinates
    int maze[ROWS][COLS] = {
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    int startRow = 0, startCol = 0;
    int targetRow = 9, targetCol = 9;

    // Find the shortest path
    int visited[ROWS][COLS] = {0};
    Node* path = findPath(maze, visited, startRow, startCol, targetRow, targetCol);

    // Print the path
    printf("Shortest path from (%d,%d) to (%d,%d):\n", startRow, startCol, targetRow, targetCol);
    while (path != NULL) {
        printf("(%d,%d) ", path->row, path->col);
        path = path->next;
    }
    printf("\n");

    return 0;
}