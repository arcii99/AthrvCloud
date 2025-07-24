//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: protected
#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

// Define the input matrix
int matrix[ROWS][COLS] = {
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1}
};

// Define the start and end positions
int startX = 0;
int startY = 0;
int endX = 4;
int endY = 4;

// Define the visited matrix
bool visited[ROWS][COLS] = {false};

// Define a function to check if a given position is valid (within the bounds of the matrix)
bool isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// Define a recursive function to find the path from the start to the end
bool findPath(int row, int col) {
    if (!isValid(row, col) || matrix[row][col] == 0 || visited[row][col]) {
        return false;
    }

    visited[row][col] = true;

    if (row == endX && col == endY) {
        return true;
    }

    if (findPath(row, col + 1) || findPath(row + 1, col) || findPath(row, col - 1) || findPath(row - 1, col)) {
        return true;
    }

    return false;
}

int main() {
    if (findPath(startX, startY)) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}