//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define maze size
#define ROWS 12
#define COLS 20

// define maze cells
#define WALL '#'
#define PATH ' '

// function to initialize maze
void initMaze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS -1) {
                maze[i][j] = WALL;
            } else {
                maze[i][j] = PATH;
            }
        }
    }
}

// function to print maze
void printMaze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// function to generate maze recursively
void generateMaze(char maze[ROWS][COLS], int row, int col) {
    maze[row][col] = WALL;
    int directions[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
    int randomDirection = rand() % 4;
    int i;
    for (i = 0; i < 4; i++) {
        int newRow = row + directions[randomDirection][0];
        int newCol = col + directions[randomDirection][1];
        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == PATH) {
            int wallRow = row + directions[randomDirection][0] / 2;
            int wallCol = col + directions[randomDirection][1] / 2;
            maze[wallRow][wallCol] = WALL;
            generateMaze(maze, newRow, newCol);
        }
        randomDirection = (randomDirection + 1) % 4;
    }
}

int main() {
    char maze[ROWS][COLS];
    srand(time(NULL));
    initMaze(maze);
    generateMaze(maze, 1, 1);
    printMaze(maze);
    return 0;
}