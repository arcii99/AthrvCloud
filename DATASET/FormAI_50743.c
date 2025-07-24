//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Maze
int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}
};

// Visited
int visited[ROWS][COLS] = {0};

// Movements
int moves[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

// Print maze
void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("██");
            } else if (visited[i][j] == 1) {
                printf("░░");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Check if position is a valid move
int isValidMove(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    if (maze[row][col] == 1) {
        return 0;
    }
    if (visited[row][col] == 1) {
        return 0;
    }
    return 1;
}

// Find path
int findPath(int row, int col) {
    visited[row][col] = 1;

    if (row == ROWS - 1 && col == COLS - 1) {
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if (isValidMove(newRow, newCol)) {
            if (findPath(newRow, newCol)) {
                return 1;
            }
        }
    }

    visited[row][col] = 0;
    return 0;
}

int main() {
    int startRow = 0;
    int startCol = 0;

    if (findPath(startRow, startCol)) {
        printf("Path found!\n");
    } else {
        printf("Path not found!\n");
    }

    printMaze();

    return EXIT_SUCCESS;
}