//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 6
#define COL 7

int map[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 1, 1},
    {0, 1, 1, 1, 0, 0, 0}
};

bool pathExists(int row, int col) {
    if (row == ROW - 1 && col == COL - 1) {
        // End Point has been reached
        printf("[%d, %d]\n", row, col);
        return true;
    }
    
    if (row < ROW && col < COL && map[row][col] == 0) {
        // Point is available
        printf("[%d, %d]\n", row, col);
        map[row][col] = 2;
        
        if (pathExists(row, col + 1)) {
            // Check Right
            return true;
        }

        if (pathExists(row + 1, col)) {
            // Check Down
            return true;
        }

        if (pathExists(row, col - 1)) {
            // Check Left
            return true;
        }
        
        if (pathExists(row - 1, col)) {
            // Check Up
            return true;
        }
        
        // Point has no Path
        map[row][col] = 0;
        return false;
    }

    return false;
}

int main() {
    if (!pathExists(0, 0)) {
        printf("No Path Exists.");
    }

    return 0;
}