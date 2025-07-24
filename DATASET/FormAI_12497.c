//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAZE_WIDTH 25
#define MAZE_HEIGHT 25

char maze[MAZE_HEIGHT][MAZE_WIDTH]; // 2D array to store maze

void initMaze() {
    int i, j;
    for (i = 0; i < MAZE_HEIGHT; i++) {
        for (j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j] = '#'; // set all cells to wall initially
        }
    }
}

void printMaze() {
    int i, j;
    for (i = 0; i < MAZE_HEIGHT; i++) {
        for (j = 0; j < MAZE_WIDTH; j++) {
            printf("%c", maze[i][j]); // print maze cell
        }
        printf("\n"); // move to next row
    }
}

bool isSafe(int row, int col) {
    if (row < 0 || col < 0 || row >= MAZE_HEIGHT || col >= MAZE_WIDTH || maze[row][col] == ' ') {
        // cell is outside maze or already visited
        return false;
    }
    return true;
}

void createMaze(int row, int col) {
    int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // possible moves
    int i, rnd, next_row, next_col;
    bool moveDone = false;
    while (!moveDone) {
        rnd = rand() % 4; // pick a random move
        next_row = row + moves[rnd][0]; // calculate next row
        next_col = col + moves[rnd][1]; // calculate next column
        if (isSafe(next_row, next_col)) {
            // make move
            maze[next_row][next_col] = ' ';
            createMaze(next_row, next_col);
            moveDone = true;
        }
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    initMaze(); // initialize maze with walls
    maze[1][0] = ' '; // start
    maze[MAZE_HEIGHT - 2][MAZE_WIDTH - 1] = ' '; // finish
    createMaze(1, 0); // generate maze recursively
    printMaze(); // print maze
    return 0;
}