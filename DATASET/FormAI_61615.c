//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
#include <stdio.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
    {'#', '.', '#', '#', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '#', '#', '#'}
};
int startRow = 1, startCol = 1, endRow = 8, endCol = 9;

int dfs(int row, int col) {
    if(maze[row][col] == '#') {
        return 0;
    }
    if(row == endRow && col == endCol) {
        return 1; // Found the end!
    }
    maze[row][col] = '#'; // Mark as visited
    if(dfs(row+1, col)) { // Check cell below
        printf("DOWN ");
        return 1;
    }
    if(dfs(row, col+1)) { // Check cell to the right
        printf("RIGHT ");
        return 1;
    }
    if(dfs(row-1, col)) { // Check cell above
        printf("UP ");
        return 1;
    }
    if(dfs(row, col-1)) { // Check cell to the left
        printf("LEFT ");
        return 1;
    }
    return 0;
}

int main() {
    dfs(startRow, startCol);
    printf("\n");
    return 0;
}