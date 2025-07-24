//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS]; // the maze cells representing walls

void initialiseMaze() { // initialise the maze to be all walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }
}

void printMaze() { // print out the maze, 0 being a path and 1 being a wall
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int isPath(int row, int col) { // check whether the cell is already a path
    if (maze[row][col] == 0) {
        return 1;
    }
    return 0;
}

int isInsideMaze(int row, int col) { // check whether the cell is inside the maze
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        return 1;
    }
    return 0;
}

void carvePath(int row, int col) { // recuresively select random paths until the boundary of the maze is reached
    int directions[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }; // right, down, left, up

    for (int i = 0; i < 4; i++) { // randomly shuffle the directions array
        int temp = directions[i][0];
        directions[i][0] = directions[rand() % 4][0];
        directions[rand() % 4][0] = temp;

        temp = directions[i][1];
        directions[i][1] = directions[rand() % 4][1];
        directions[rand() % 4][1] = temp;
    }

    for (int i = 0; i < 4; i++) { // attempt to carve out a path in each of the directions
        int nextRow = row + directions[i][0] * 2;
        int nextCol = col + directions[i][1] * 2;

        if (isInsideMaze(nextRow, nextCol) && isPath(nextRow, nextCol) == 0) {
            maze[row + directions[i][0]][col + directions[i][1]] = 0;
            maze[nextRow][nextCol] = 0;
            carvePath(nextRow, nextCol);
        }
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator

    initialiseMaze(); // initialise the maze

    int startRow = rand() % ROWS; // randomly select the start cell
    int startCol = rand() % COLS;
    maze[startRow][startCol] = 0;

    carvePath(startRow, startCol); // recursively carve out the maze

    printMaze(); // print out the maze

    return 0;
}