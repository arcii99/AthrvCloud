//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// function to print the maze
void printMaze(int maze[ROWS][COLS], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c ", maze[i][j]?'#':' ');
        }
        printf("\n");
    }
}

// function to check if a move is valid
int isValidMove(int x, int y, int row, int col) {
    if (x < 0 || x > row - 1 || y < 0 || y > col - 1) // check if move is within bounds
        return 0;
    return 1;
}

// recursive function to generate the maze
void generateMaze(int maze[ROWS][COLS], int x, int y, int row, int col) {
    int dx[4] = {0, 0, 1, -1}; // array for x-direction movements
    int dy[4] = {1, -1, 0, 0}; // array for y-direction movements

    maze[x][y] = 1; // mark current cell as visited

    // randomly shuffle the directions
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = dx[r];
        dx[r] = dx[i];
        dx[i] = temp;

        temp = dy[r];
        dy[r] = dy[i];
        dy[i] = temp;
    }

    // explore each direction
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // check if move is valid and the cell is unvisited
        if (isValidMove(newX, newY, row, col) && maze[newX][newY] == 0) {
            // mark the wall between the current cell and the next cell as removed
            maze[x + dx[i]/2][y + dy[i]/2] = 1;
            // recursively generate the maze from the next cell
            generateMaze(maze, newX, newY, row, col);
        }
    }
}

int main() {
    int maze[ROWS][COLS] = {0}; // initialize all cells to unvisited
    srand(time(NULL)); // seed the random number generator

    generateMaze(maze, 0, 0, ROWS, COLS); // start maze generation from top-left corner
    printMaze(maze, ROWS, COLS); // print the maze

    return 0;
}