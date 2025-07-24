//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROWS 10
#define COLS 10

/* Function to print the maze */
void printMaze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

/* Recursive function to find the path to exit */
bool findPath(char maze[ROWS][COLS], int row, int col) {
    /* If row or col is out of range, return false */
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }
    /* If the current cell is the exit, return true */
    if (maze[row][col] == 'E') {
        return true;
    }
    /* If the current cell is a wall, return false */
    if (maze[row][col] == '#') {
        return false;
    }
    /* If the current cell is already visited, return false */
    if (maze[row][col] == '.') {
        return false;
    }
    /* Mark the current cell as visited */
    maze[row][col] = '.';
    /* Recursively check for path in all four directions */
    if (findPath(maze, row + 1, col)) { // Check south
        return true;
    }
    if (findPath(maze, row, col + 1)) { // Check east
        return true;
    }
    if (findPath(maze, row - 1, col)) { // Check north
        return true;
    }
    if (findPath(maze, row, col - 1)) { // Check west
        return true;
    }
    /* If no path found, backtrack */
    maze[row][col] = ' ';
    return false;
}

int main() {
    /* Define the maze */
    char maze[ROWS][COLS] = {
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#',' ','#',' ','#',' ',' ',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#','#','#','#'},
        {'#',' ','#',' ','#',' ','#',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ','#','#'},
        {'#',' ',' ',' ','#',' ','#',' ','#','#'},
        {'#','#','#',' ','#',' ','#',' ','#','#'},
        {'#',' ',' ',' ',' ',' ','#',' ',' ','#'},
        {'#','#','#','#','#','#','#','#',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ','#','#'},
    };
    /* Find the path */
    if (findPath(maze, 1, 1)) {
        printf("Path found!\n");
    } else {
        printf("No path found!\n");
    }
    /* Print the maze */
    printMaze(maze);
    return 0;
}