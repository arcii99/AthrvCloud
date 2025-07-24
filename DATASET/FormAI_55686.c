//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// define maze dimensions
#define ROWS 10
#define COLS 10

// function prototypes
void printMaze(int maze[][COLS]);
void findRoute(int maze[][COLS], int row, int col);

int main() {
    // define maze
    int maze[ROWS][COLS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    };

    // print initial maze
    printf("Initial maze:\n");
    printMaze(maze);

    // find route from starting point (1, 1)
    printf("\nRoute finding process:\n");
    findRoute(maze, 1, 1);

    // print final maze with route marked
    printf("\nMaze with route:\n");
    printMaze(maze);

    return 0;
}

// function to print maze
void printMaze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// function to find route in maze, using recursive backtracking algorithm
void findRoute(int maze[][COLS], int row, int col) {
    // mark current location as visited
    maze[row][col] = 2;

    // if we have reached the end of the maze, return
    if (row == ROWS-2 && col == COLS-2) {
        return;
    }

    // check adjacent cells for possible route
    if (maze[row-1][col] == 0) {
        findRoute(maze, row-1, col); // move up
        if (maze[row-1][col] != 2) {
            maze[row-1][col] = 0;
        }
    }

    if (maze[row][col+1] == 0) {
        findRoute(maze, row, col+1); // move right
        if (maze[row][col+1] != 2) {
            maze[row][col+1] = 0;
        }
    }

    if (maze[row+1][col] == 0) {
        findRoute(maze, row+1, col); // move down
        if (maze[row+1][col] != 2) {
            maze[row+1][col] = 0;
        }
    }

    if (maze[row][col-1] == 0) {
        findRoute(maze, row, col-1); // move left
        if (maze[row][col-1] != 2) {
            maze[row][col-1] = 0;
        }
    }
}