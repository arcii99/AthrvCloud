//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

int maze[ROWS][COLS] = {
    {0, 0, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
};

bool visited[ROWS][COLS];
int start_row, start_col, end_row, end_col;

/*
* Returns true if the cell is valid (not out of bounds and not a wall)
*/
bool is_valid(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || maze[row][col] == 1 || visited[row][col]) {
        return false;
    }
    return true;
}

/*
* Recursively searches for the end of the maze using DFS
*/
bool dfs(int row, int col) {
    if (row == end_row && col == end_col) {
        return true;
    }
    visited[row][col] = true;
    if (is_valid(row+1, col) && dfs(row+1, col)) {
        return true;
    }
    if (is_valid(row-1, col) && dfs(row-1, col)) {
        return true;
    }
    if (is_valid(row, col+1) && dfs(row, col+1)) {
        return true;
    }
    if (is_valid(row, col-1) && dfs(row, col-1)) {
        return true;
    }
    return false;
}

/*
* Finds the path from the start to the end using DFS and prints it
*/
void find_path() {
    if (!dfs(start_row, start_col)) {
        printf("No path found!\n");
        return;
    }
    printf("Path found!\n");
    int row = end_row, col = end_col;
    while (row != start_row || col != start_col) {
        printf("(%d,%d) -> ", row, col);
        visited[row][col] = false;
        if (row > 0 && visited[row-1][col]) {
            row--;
        }
        else if (row < ROWS-1 && visited[row+1][col]) {
            row++;
        }
        else if (col > 0 && visited[row][col-1]) {
            col--;
        }
        else if (col < COLS-1 && visited[row][col+1]) {
            col++;
        }
    }
    printf("(%d,%d)\n", start_row, start_col);
}

int main() {
    start_row = 0, start_col = 0;
    end_row = 4, end_col = 4;
    find_path();
    return 0;
}