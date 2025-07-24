//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define rows and cols for the maze dimensions
#define ROWS 8
#define COLS 8

// Define directions with proper offsets
#define NORTH -1, 0
#define SOUTH 1, 0
#define EAST 0, 1
#define WEST 0, -1

// The maze represented as a 2D array
char maze[ROWS][COLS] = {
    {'S', '.', '.', '.', '.', '.', '.', '.'},
    {'.', 'X', '.', '.', '.', '.', '.', '.'},
    {'.', '.', 'X', '.', '.', 'X', '.', 'X'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', 'X', '.', '.', '.', '.', '.'},
    {'.', 'X', '.', '.', 'X', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', 'X', '.'},
    {'.', '.', '.', '.', '.', '.', '.', 'E'}
};

// Define a struct to hold the position of the current node
typedef struct {
    int row;
    int col;
} Node;

// Helper function to check if a given position is within the maze boundaries
bool inBounds(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// Helper function to check if a given position is not a wall
bool isPassable(int row, int col) {
    return (maze[row][col] != 'X');
}

// Helper function to check if a given position is the end
bool isEnd(int row, int col) {
    return (maze[row][col] == 'E');
}

// Helper function to print the maze with the given path
void printMaze(Node path[], int pathLength) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (maze[row][col] == 'S' || maze[row][col] == 'E') {
                printf("%c", maze[row][col]);
            } else {
                bool partOfPath = false;
                for (int i = 0; i < pathLength; i++) {
                    if (path[i].row == row && path[i].col == col) {
                        printf("*");
                        partOfPath = true;
                        break;
                    }
                }
                if (!partOfPath) {
                    printf("%c", maze[row][col]);
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

// The main function to find a path through the maze
bool findPath(int row, int col, Node path[], int pathLength) {
    // Check if we've reached the end
    if (isEnd(row, col)) {
        printMaze(path, pathLength);
        return true;
    }

    // Mark this node as part of the path
    path[pathLength].row = row;
    path[pathLength].col = col;

    // Check the neighbors in all four directions
    int directions[4][2] = {NORTH, SOUTH, EAST, WEST};
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];
        if (inBounds(newRow, newCol) && isPassable(newRow, newCol)) {
            // Recurse on this neighbor
            if (findPath(newRow, newCol, path, pathLength+1)) {
                return true;
            }
        }
    }

    // If no path found from this node, backtrack
    return false;
}

// The main function to initiate the pathfinding algorithm
int main() {
    // Find the starting position
    Node start;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (maze[row][col] == 'S') {
                start.row = row;
                start.col = col;
            }
        }
    }

    // Start the pathfinding algorithm
    Node path[ROWS*COLS];
    findPath(start.row, start.col, path, 0);

    return 0;
}