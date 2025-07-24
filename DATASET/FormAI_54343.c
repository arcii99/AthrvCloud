//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 25

void generateMaze(int maze[ROWS][COLS], int row, int col);
void printMaze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL));
    generateMaze(maze, 0, 0);
    printMaze(maze);
    return 0;
}

void generateMaze(int maze[ROWS][COLS], int row, int col) {
    // Initialize the maze with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // Create a path starting at the specified row and column
    maze[row][col] = 0;

    // Generate the maze using depth-first search algorithm
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = directions[r][0];
        directions[r][0] = directions[i][0];
        directions[i][0] = temp;
        temp = directions[r][1];
        directions[r][1] = directions[i][1];
        directions[i][1] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int nextRow = row + directions[i][0];
        int nextCol = col + directions[i][1];
        if (nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && maze[nextRow][nextCol] == 1) {
            maze[row + directions[i][0] / 2][col + directions[i][1] / 2] = 0;
            generateMaze(maze, nextRow, nextCol);
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("\u2588\u2588");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}