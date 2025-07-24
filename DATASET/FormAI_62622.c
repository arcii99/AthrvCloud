//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// function to print the maze
void print_maze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// function to check if cell is valid
bool is_valid(int row, int col, char maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    if (row >= 0 && row < rows && col >= 0 && col < cols && maze[row][col] == '.') {
        return true;
    }
    return false;
}

// function to find the path in the maze
bool find_path(int row, int col, char maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    // if we reach the end of the maze, return true
    if (row == rows - 1 && col == cols - 1) {
        maze[row][col] = 'E';
        return true;
    }
    
    // mark the current cell as visited
    maze[row][col] = 'X';
    
    // explore all possible directions
    if (is_valid(row + 1, col, maze, rows, cols)) { // down
        if (find_path(row + 1, col, maze, rows, cols)) {
            maze[row][col] = 'E';
            return true;
        }
    }
    if (is_valid(row, col + 1, maze, rows, cols)) { // right
        if (find_path(row, col + 1, maze, rows, cols)) {
            maze[row][col] = 'E';
            return true;
        }
    }
    if (is_valid(row - 1, col, maze, rows, cols)) { // up
        if (find_path(row - 1, col, maze, rows, cols)) {
            maze[row][col] = 'E';
            return true;
        }
    }
    if (is_valid(row, col - 1, maze, rows, cols)) { // left
        if (find_path(row, col - 1, maze, rows, cols)) {
            maze[row][col] = 'E';
            return true;
        }
    }
    
    return false;
}

int main() {
    char maze[MAX_ROWS][MAX_COLS] = {
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'}
    };
    
    int rows = MAX_ROWS;
    int cols = MAX_COLS;
    
    printf("The maze starts!\n");
    print_maze(maze, rows, cols);
    
    if (find_path(0, 0, maze, rows, cols)) {
        printf("\nCongratulations! The route has been found.\n");
        print_maze(maze, rows, cols);
    } else {
        printf("\nOops! There is no route in this maze.\n");
        print_maze(maze, rows, cols);
    }
    
    return 0;
}