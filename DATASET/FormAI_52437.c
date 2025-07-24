//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {  // Hardcoded maze
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

struct Position {  // Structure to hold the position of maze blocks
    int row;
    int col;
};

int is_valid_move(int row, int col) {  // Check if position is valid in the maze
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return 0;
    }
    if (maze[row][col] == 1) {
        return 0;
    }
    return 1;
}

void print_maze() {  // Print the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int find_path(int start_row, int start_col, int end_row, int end_col) {  // Recursive function to find path
    static int path_count = 1;  // Static variable to keep track of path count
    if (start_row == end_row && start_col == end_col) {  // Base case if we find the end position
        printf("Path %d:\n", path_count++);
        print_maze();
        return 1;
    }
    if (is_valid_move(start_row, start_col)) {  // Check if current position is valid
        maze[start_row][start_col] = 2;  // Mark current position as visited
        if (find_path(start_row-1, start_col, end_row, end_col)) {  // Recurse for up
            return 1;
        }
        if (find_path(start_row+1, start_col, end_row, end_col)) {  // Recurse for down
            return 1;
        }
        if (find_path(start_row, start_col-1, end_row, end_col)) {  // Recurse for left
            return 1;
        }
        if (find_path(start_row, start_col+1, end_row, end_col)) {  // Recurse for right
            return 1;
        }
        maze[start_row][start_col] = 0;  // If we can't find a path from current position, unmark it
        return 0;
    }
    return 0;
}

int main() {
    printf("Maze:\n");
    print_maze();
    struct Position start = {1, 1};  // Start position
    struct Position end = {ROWS-2, COLS-2};  // End position
    printf("Finding paths...\n");
    find_path(start.row, start.col, end.row, end.col);
    printf("Done.\n");
    return 0;
}