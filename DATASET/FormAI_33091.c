//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15 // number of rows in the maze
#define COLS 15 // number of columns in the maze
#define START_ROW 0 // starting row of the maze
#define START_COL 0 // starting column of the maze
#define END_ROW (ROWS-1) // ending row of the maze
#define END_COL (COLS-1) // ending column of the maze

// function prototypes
void generateMaze(int maze[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];

    // seed the random number generator
    srand(time(NULL));

    // generate the maze
    generateMaze(maze);

    // print the maze
    printMaze(maze);

    return 0;
}

// function to generate the maze
void generateMaze(int maze[ROWS][COLS]) {
    int i, j, direction, numDirections, row = START_ROW, col = START_COL;
    int visited[ROWS][COLS] = {0}; // array to keep track of visited cells
    int stack[ROWS*COLS][2], top = -1; // stack to keep track of previous cell

    // initialize the maze
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = 1; // set all cells to walls
        }
    }

    // mark the starting cell as visited
    visited[row][col] = 1;

    do {
        // get the number of possible directions
        numDirections = 0;
        if (row > 0 && !visited[row-1][col]) {
            numDirections++;
        }
        if (row < ROWS-1 && !visited[row+1][col]) {
            numDirections++;
        }
        if (col > 0 && !visited[row][col-1]) {
            numDirections++;
        }
        if (col < COLS-1 && !visited[row][col+1]) {
            numDirections++;
        }

        if (numDirections > 0) {
            // choose a random direction
            direction = rand() % numDirections;

            // push the current cell onto the stack
            top++;
            stack[top][0] = row;
            stack[top][1] = col;

            // mark the next cell as visited and remove the wall between the cells
            if (direction == 0 && row > 0 && !visited[row-1][col]) {
                maze[row][col] &= ~1; // remove the top wall of the current cell
                row--;
                visited[row][col] = 1;
                maze[row][col] &= ~4; // remove the bottom wall of the next cell
            } else if (direction == 1 && row < ROWS-1 && !visited[row+1][col]) {
                maze[row][col] &= ~4; // remove the bottom wall of the current cell
                row++;
                visited[row][col] = 1;
                maze[row][col] &= ~1; // remove the top wall of the next cell
            } else if (direction == 2 && col > 0 && !visited[row][col-1]) {
                maze[row][col] &= ~8; // remove the left wall of the current cell
                col--;
                visited[row][col] = 1;
                maze[row][col] &= ~2; // remove the right wall of the next cell
            } else if (direction == 3 && col < COLS-1 && !visited[row][col+1]) {
                maze[row][col] &= ~2; // remove the right wall of the current cell
                col++;
                visited[row][col] = 1;
                maze[row][col] &= ~8; // remove the left wall of the next cell
            }
        } else {
            // backtrack to the previous cell on the stack
            row = stack[top][0];
            col = stack[top][1];
            top--;
        }

    } while (top >= 0);
}

// function to print the maze
void printMaze(int maze[ROWS][COLS]) {
    int i, j;

    // print the top border of the maze
    for (i = 0; i <= COLS; i++) {
        printf("+--");
    }
    printf("+\n");

    // print each row of the maze
    for (i = 0; i < ROWS; i++) {
        printf("|"); // left border of the maze
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] & 1) {
                printf("  |"); // top wall
            } else {
                printf("   "); // no top wall
            }
        }
        printf("\n");

        printf("+"); // start of next row

        for (j = 0; j < COLS; j++) {
            if (maze[i][j] & 8) {
                printf("--"); // left wall
            } else {
                printf("  "); // no left wall
            }

            if (i == END_ROW && j == END_COL) {
                printf("E"); // end of the maze
            } else if (maze[i][j] & 4) {
                printf("|"); // bottom wall
            } else {
                printf(" "); // no bottom wall
            }

            if (j == COLS-1) {
                printf("+"); // right border of the maze
            }
        }
        printf("\n");
    }
}