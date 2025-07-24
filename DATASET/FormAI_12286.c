//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(int maze[][COLS], int row, int col);
void printMaze(int maze[][COLS], int row, int col);

int main(void) {
    int maze[ROWS][COLS];

    srand(time(NULL)); // Set the seed for random number generation.

    generateMaze(maze, ROWS, COLS);
    printMaze(maze, ROWS, COLS);

    return 0;
}

void generateMaze(int maze[][COLS], int row, int col) {
    // Set all cells to be walls initially.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            maze[i][j] = 1;
        }
    }

    // Set the starting cell to be a passage.
    maze[1][1] = 0;

    // Initialize variables for generating the maze.
    int x = 1, y = 1;
    int dx[4] = {0, 1, 0, -1}; // Shifts for row, column pairs.
    int dy[4] = {1, 0, -1, 0};
    int stack[row * col][2], top = 0; // Stack for backtracking.
    stack[top][0] = x;
    stack[top][1] = y;

    // Generate the maze.
    while (top >= 0) {
        int dir = rand() % 4; // Choose a random direction.
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx > 0 && ny > 0 && nx < row - 1 && ny < col - 1 &&
                maze[nx][ny] == 1) {
            // Carve a passage and push the current cell onto the stack.
            maze[nx][ny] = 0;
            maze[x + dx[dir] / 2][y + dy[dir] / 2] = 0;
            stack[++top][0] = x = nx;
            stack[top][1] = y = ny;
        } else {
            // Backtrack.
            x = stack[top][0];
            y = stack[top--][1];
        }
    }
}

void printMaze(int maze[][COLS], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}