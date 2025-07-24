//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

enum direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

// Create the maze using a depth-first search algorithm
void createMaze(int maze[ROWS][COLS], int row, int col) {
    enum direction dirArray[4] = {NORTH, EAST, SOUTH, WEST};
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        enum direction temp = dirArray[r];
        dirArray[r] = dirArray[i];
        dirArray[i] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int r = row, c = col; // initialize row and column
        switch (dirArray[i]) {
            case NORTH:
                r = row - 1;
                break;
            case EAST:
                c = col + 1;
                break;
            case SOUTH:
                r = row + 1;
                break;
            case WEST:
                c = col - 1;
                break;
        }
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || maze[r][c]) {
            continue;
        }
        switch (dirArray[i]) {
            case NORTH:
                maze[row - 1][col] = 1;
                break;
            case EAST:
                maze[row][col + 1] = 1;
                break;
            case SOUTH:
                maze[row + 1][col] = 1;
                break;
            case WEST:
                maze[row][col - 1] = 1;
                break;
        }
        createMaze(maze, r, c);
    }
}

// Print the maze with ASCII characters
void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int maze[ROWS][COLS] = {0}; // initialize the maze to all walls
    int startRow = rand() % ROWS;
    int startCol = rand() % COLS;
    maze[startRow][startCol] = 1; // set the starting position
    createMaze(maze, startRow, startCol);
    printMaze(maze);
    return 0;
}