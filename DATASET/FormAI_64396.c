//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 10    // The number of rows in the maze.
#define COL_SIZE 10    // The number of columns in the maze.

typedef struct {
    int row;
    int col;
} Point;

// This function prints the maze.
void print_maze(char maze[ROW_SIZE][COL_SIZE]) {
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// This function checks if a given point is valid (inside the maze and not a wall).
int is_valid_point(Point p, char maze[ROW_SIZE][COL_SIZE]) {
    if (p.row >= 0 && p.row < ROW_SIZE && p.col >= 0 && p.col < COL_SIZE) {
        return maze[p.row][p.col] != 'X';
    }
    return 0;
}

// This function checks if a given point is the exit point of the maze.
int is_exit_point(Point p) {
    return (p.row == ROW_SIZE - 1 && p.col == COL_SIZE - 1);
}

// This function finds the exit path of the maze using depth-first search algorithm.
int find_exit_path(int current_row, int current_col, Point path[], int path_length, char maze[ROW_SIZE][COL_SIZE]) {
    // Create the current point.
    Point current_point = { current_row, current_col };
    
    // If the current point is invalid or part of an already visited path, return 0.
    if (!is_valid_point(current_point, maze) || maze[current_row][current_col] == 'V') {
        return 0;
    }
    
    // Add the current point to the path and mark it as visited.
    path[path_length] = current_point;
    path_length++;
    maze[current_row][current_col] = 'V';
    
    // If the current point is the exit point, return 1.
    if (is_exit_point(current_point)) {
        return 1;
    }
    
    // Recursively check the neighbors of the current point.
    if (find_exit_path(current_row - 1, current_col, path, path_length, maze)) {
        return 1;
    }
    if (find_exit_path(current_row, current_col + 1, path, path_length, maze)) {
        return 1;
    }
    if (find_exit_path(current_row + 1, current_col, path, path_length, maze)) {
        return 1;
    }
    if (find_exit_path(current_row, current_col - 1, path, path_length, maze)) {
        return 1;
    }
    
    // If the current point is not part of the exit path, remove it from the path and return 0.
    path_length--;
    maze[current_row][current_col] = '.';
    return 0;
}

int main() {
    char maze[ROW_SIZE][COL_SIZE] = {
        { '.', '.', '.', '.', '.', '.', '.', 'X', '.', '.' },
        { 'X', '.', 'X', 'X', 'X', 'X', '.', 'X', '.', 'X' },
        { '.', '.', '.', '.', '.', '.', '.', 'X', '.', '.' },
        { '.', 'X', '.', 'X', '.', 'X', '.', 'X', '.', '.' },
        { '.', 'X', '.', '.', '.', '.', '.', '.', '.', 'X' },
        { '.', 'X', '.', 'X', 'X', 'X', 'X', 'X', '.', '.' },
        { '.', '.', '.', '.', '.', 'X', '.', '.', '.', '.' },
        { 'X', 'X', 'X', 'X', '.', 'X', '.', 'X', 'X', 'X' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', 'X', 'X', 'X', 'X', '.', '.', '.', '.', 'X' }
    };
    
    // Print the maze.
    printf("The maze:\n");
    print_maze(maze);
    
    // Find the exit path of the maze.
    Point path[ROW_SIZE * COL_SIZE];
    int path_length = 0;
    find_exit_path(0, 0, path, path_length, maze);
    
    // Print the exit path
    printf("The exit path:\n");
    int i;
    for (i = 0; i < path_length; i++) {
        printf("(%d, %d) -> ", path[i].row, path[i].col);
    }
    printf("EXIT\n");
    
    return 0;
}