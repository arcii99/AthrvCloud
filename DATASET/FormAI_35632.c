//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 6

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1},
};

bool visited[ROWS][COLS];

bool isValid(int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return false;
    }
    
    if (maze[row][col] == 0 || visited[row][col] == true) {
        return false;
    }
    
    return true;
}

bool solveMaze(int row, int col) {
    if (row == ROWS - 1 && col == COLS - 1) {
        return true;
    }
    
    if (isValid(row, col) == true) {
        visited[row][col] = true;
        
        if (solveMaze(row + 1, col) == true) { // down
            return true;
        }

        if (solveMaze(row, col + 1) == true) { // right
            return true;
        }

        if (solveMaze(row - 1, col) == true) { // up
            return true;
        }

        if (solveMaze(row, col - 1) == true) { // left
            return true;
        }

        visited[row][col] = false;
        return false;
    }

    return false;
}

int main(void) {
    if (solveMaze(0, 0) == true) {
        printf("Maze can be solved!\n");
    } else {
        printf("Maze cannot be solved!\n");
    }

    return 0;
}