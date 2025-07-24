//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Function to print the maze
void printMaze(char maze[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to find if a particular cell is valid to move or not
bool isValid(char maze[][COLS], int row, int col) {
    if(row>=0 && row<ROWS && col>=0 && col<COLS && maze[row][col]==' ') {
        return true;
    }
    return false;
}

// Function to find the path through maze using recursive approach
bool findPath(char maze[][COLS], int row, int col) {
    if(row==ROWS-1 && col==COLS-1) {
        return true;
    }

    if(isValid(maze, row, col)) {
        maze[row][col] = 'P';

        // Move Down
        if(findPath(maze, row+1, col)) {
            return true;
        }

        // Move Right
        if(findPath(maze, row, col+1)) {
            return true;
        }

        // Move Up
        if(findPath(maze, row-1, col)) {
            return true;
        }

        // Move Left
        if(findPath(maze, row, col-1)) {
            return true;
        }

        maze[row][col] = ' ';
        return false;
    }
    return false;
}

int main() {
    char maze[ROWS][COLS] = {
        {' ', '*', '*', ' ', '*', '*', ' ', ' ', '*', ' '},
        {' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*'},
        {'*', '*', '*', '*', ' ', '*', ' ', '*', ' ', '*'},
        {' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', '*'},
        {' ', '*', ' ', ' ', ' ', '*', ' ', '*', '*', ' '},
        {' ', '*', '*', '*', ' ', '*', ' ', ' ', ' ', ' '},
        {' ', '*', ' ', ' ', ' ', '*', '*', '*', '*', ' '},
        {' ', '*', '*', '*', '*', '*', ' ', ' ', '*', ' '},
        {' ', '*', ' ', ' ', '*', '*', '*', '*', '*', '*'},
        {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' '},
    };

    printf("Original Maze: \n");
    printMaze(maze);

    if(findPath(maze, 0, 0)) {
        printf("\nPath Found Through Maze: \n");
        printMaze(maze);
    } else {
        printf("\nNo Path Found Through Maze :(\n");
    }

    return 0;
}