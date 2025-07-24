//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Function to print the maze on the screen
void print_maze(char maze[ROWS][COLS], int rows, int cols) {
    printf("----------------------------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------\n");
}

// Function to check if the given position is valid in the maze
int is_valid_pos(int row, int col, int rows, int cols) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

// Function to check if the given position is clear in the maze
int is_clear_pos(int row, int col, char maze[ROWS][COLS]) {
    return (is_valid_pos(row, col, ROWS, COLS) && maze[row][col] == '.');
}

// Function to find the path in the maze
int find_path(int row, int col, char maze[ROWS][COLS], int rows, int cols) {
    // If the current position is the end position, return 1 to indicate success
    if (row == rows-1 && col == cols-1) {
        return 1;
    }
    // If the current position is clear, mark it as visited and try to move in all directions
    if (is_clear_pos(row, col, maze)) {
        maze[row][col] = 'v';
        // Try to move up
        if (find_path(row-1, col, maze, rows, cols)) {
            return 1;
        }
        // Try to move down
        if (find_path(row+1, col, maze, rows, cols)) {
            return 1;
        }
        // Try to move left
        if (find_path(row, col-1, maze, rows, cols)) {
            return 1;
        }
        // Try to move right
        if (find_path(row, col+1, maze, rows, cols)) {
            return 1;
        }
        // If none of the directions lead to success, mark the position as blocked and backtrack
        maze[row][col] = 'b';
    }
    return 0;
}

// Main function
int main() {
    char maze[ROWS][COLS] = {
        { '.', '.', '.', '#', '.', '.', '.', '.', '.', '.' },
        { '.', '#', '.', '.', '.', '#', '.', '.', '#', '.' },
        { '.', '#', '.', '#', '.', '.', '#', '.', '#', '.' },
        { '.', '.', '#', '.', '#', '#', '.', '#', '.', '.' },
        { '#', '.', '#', '.', '.', '#', '.', '.', '.', '#' },
        { '.', '.', '#', '#', '.', '.', '.', '#', '#', '.' },
        { '.', '#', '.', '#', '#', '.', '.', '#', '.', '.' },
        { '#', '.', '.', '.', '#', '.', '#', '.', '.', '#' },
        { '#', '.', '.', '#', '.', '#', '.', '#', '.', '.' },
        { '.', '.', '.', '.', '#', '#', '.', '.', '.', '.' },
    };
    printf("Maze before:\n");
    print_maze(maze, ROWS, COLS);
    if (find_path(0, 0, maze, ROWS, COLS)) {
        printf("Path found!\n");
    } else {
        printf("Path not found!\n");
    }
    printf("Maze after:\n");
    print_maze(maze, ROWS, COLS);
    return 0;
}