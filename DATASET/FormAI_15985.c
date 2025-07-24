//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_ROWS 10
#define MAZE_COLS 20

int maze[MAZE_ROWS][MAZE_COLS]; // initialize blank map

// function to generate the maze
void generateMaze() {

    srand(time(NULL)); // seed the random number generator

    // generate random starting point
    int startRow = rand() % MAZE_ROWS;
    int startCol = rand() % MAZE_COLS;

    // set starting point as path
    maze[startRow][startCol] = 0;

    // initialize variables for current position
    int currRow = startRow;
    int currCol = startCol;

    // continue generating until all cells are paths
    while (1) {

        // check if maze is complete
        int count = 0;
        for (int i = 0; i < MAZE_ROWS; i++) {
            for (int j = 0; j < MAZE_COLS; j++) {
                if (maze[i][j] == 0) {
                    count++;
                }
            }
        }
        if (count == MAZE_ROWS * MAZE_COLS) {
            break;
        }

        // generate random direction
        int direction = rand() % 4;

        // move current position based on direction
        switch (direction) {
            case 0: // up
                if (currRow > 0 && maze[currRow-1][currCol] != 0) {
                    currRow--;
                }
                break;
            case 1: // right
                if (currCol < MAZE_COLS-1 && maze[currRow][currCol+1] != 0) {
                    currCol++;
                }
                break;
            case 2: // down
                if (currRow < MAZE_ROWS-1 && maze[currRow+1][currCol] != 0) {
                    currRow++;
                }
                break;
            case 3: // left
                if (currCol > 0 && maze[currRow][currCol-1] != 0) {
                    currCol--;
                }
                break;
        }

        // set new position as path
        maze[currRow][currCol] = 0;

    }

}

// function to print the maze
void printMaze() {

    // print top border
    printf("+");
    for (int i = 0; i < MAZE_COLS; i++) {
        printf("-");
    }
    printf("+\n");

    // print each row of maze
    for (int i = 0; i < MAZE_ROWS; i++) {
        printf("|");
        for (int j = 0; j < MAZE_COLS; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("|\n");
    }

    // print bottom border
    printf("+");
    for (int i = 0; i < MAZE_COLS; i++) {
        printf("-");
    }
    printf("+\n");

}

int main() {

    generateMaze();
    printMaze();

    return 0;
}