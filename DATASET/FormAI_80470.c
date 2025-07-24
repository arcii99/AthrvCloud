//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Function to print the maze
void printMaze(char maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if valid move
bool isValidMove(char maze[][COLS], int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS || maze[row][col] == '#' || maze[row][col] == '*') {
        return false;
    }
    return true;
}

// Recursive function to find the exit
bool findExit(char maze[][COLS], int row, int col) {
    // Base case: reached the exit
    if (maze[row][col] == 'E') {
        return true;
    }

    // Mark current cell as visited
    maze[row][col] = '*';

    // Check valid moves in all directions
    if (isValidMove(maze, row-1, col)) {
        if (findExit(maze, row-1, col)) {
            return true;
        }
    }
    if (isValidMove(maze, row+1, col)) {
        if (findExit(maze, row+1, col)) {
            return true;
        }
    }
    if (isValidMove(maze, row, col-1)) {
        if (findExit(maze, row, col-1)) {
            return true;
        }
    }
    if (isValidMove(maze, row, col+1)) {
        if (findExit(maze, row, col+1)) {
            return true;
        }
    }

    // Unmark visited cell
    maze[row][col] = ' ';

    return false;
}

int main() {
    char maze[ROWS][COLS] = {
        {'#','#','#','#','#',' ','#','#','#','#'},
        {'#',' ',' ',' ','#',' ','#',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ','#','#'},
        {'#',' ','#',' ',' ',' ','#',' ',' ','#'},
        {'#',' ','#','#','#',' ',' ','#',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ','#','#'},
        {'#',' ','#',' ',' ',' ','#',' ',' ','#'},
        {'#',' ','#','#','#',' ','#','#',' ','#'},
        {'#',' ',' ',' ','#',' ','#',' ',' ','#'},
        {'#','#','#','#','#',' ','#','#','#','E'}
    };

    printf("Welcome to the Maze Route Finder!\n");
    printf("--------------------------------\n");

    printf("The maze: \n");
    printMaze(maze);

    // Find start position
    int startRow, startCol;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == ' ') {
                startRow = i;
                startCol = j;
            }
        }
    }

    // Find exit
    if (findExit(maze, startRow, startCol)) {
        printf("\nCongratulations! You found the exit!\n");
        printf("The maze: \n");
        printMaze(maze);
    } else {
        printf("\nSorry! There is no exit in this maze.\n");
    }

    return 0;
}