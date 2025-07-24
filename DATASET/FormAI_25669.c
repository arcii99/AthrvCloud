//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: single-threaded
#include <stdio.h>

#define ROW_SIZE 10
#define COL_SIZE 10

// define the maze
int maze[ROW_SIZE][COL_SIZE] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int start_row = 1;
int start_col = 1;
int end_row = 8;
int end_col = 8;
int path_found = 0;

// function to check if a given move is valid or not
int is_valid_move(int row, int col) {
    if (row >= 0 && row < ROW_SIZE && col >= 0 && col < COL_SIZE && maze[row][col] == 0) {
        return 1;
    }
    return 0;
}

// function to recursively explore possible paths
void explore_path(int row, int col) {
    maze[row][col] = 2; // mark current cell as visited
    if (row == end_row && col == end_col) { // if end cell reached, path is found
        path_found = 1;
        return;
    }
    // explore all possible moves
    if (is_valid_move(row-1, col)) explore_path(row-1, col); // move up
    if (is_valid_move(row+1, col)) explore_path(row+1, col); // move down
    if (is_valid_move(row, col-1)) explore_path(row, col-1); // move left
    if (is_valid_move(row, col+1)) explore_path(row, col+1); // move right
    maze[row][col] = 0; // unmark current cell as visited when backtracking
}

int main() {
    explore_path(start_row, start_col); // start exploring path from starting point
    if (path_found) {
        printf("Path found!\n");
    }
    else {
        printf("Path not found!\n");
    }
    return 0;
}